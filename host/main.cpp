#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <variant>
#include <filesystem>

#include "core/IPlugin.h"
#include "core/CommandRegistry.h"
#include "core/PluginLoader.h"

// ===============================
// TOKEN PARSER
// ===============================
RuntimeValue parseToken(const std::string& token)
{
    try
    {
        size_t pos = 0;
        int value = std::stoi(token, &pos);
        if (pos == token.size())
            return value;
    }
    catch (...) {}

    return token;
}

// ===============================
// EXECUTE COMMAND
// ===============================
int executeCommand(CommandRegistry& registry, const std::string& line)
{
    std::stringstream ss(line);

    std::string cmdName;
    ss >> cmdName;

    if (cmdName.empty())
        return 0;

    std::vector<RuntimeValue> args;
    std::string token;

    while (ss >> token)
        args.push_back(parseToken(token));

    auto cmd = registry.find(cmdName);

    if (!cmd)
    {
        std::cout << "[ERROR] Command not found: " << cmdName << "\n";
        return 1;
    }

    try
    {
        RuntimeValue result = cmd->execute(args);

        if (std::holds_alternative<int>(result))
            std::cout << "[OK] " << std::get<int>(result) << "\n";
        else if (std::holds_alternative<std::string>(result))
            std::cout << "[OK] " << std::get<std::string>(result) << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << "[ERROR] " << ex.what() << "\n";
        return 1;
    }

    return 0;
}

// ===============================
// HELP
// ===============================
void printHelp(CommandRegistry& registry)
{
    std::cout << "\n+--------------------------------------+\n";
    std::cout << "|         AVAILABLE COMMANDS           |\n";
    std::cout << "+--------------------------------------+\n\n";

    auto names = registry.list();
    std::string currentCategory;

    for (const auto& n : names)
    {
        auto cmd = registry.find(n);
        if (!cmd) continue;

        if (cmd->category() != currentCategory)
        {
            currentCategory = cmd->category();
            std::cout << "\n[" << currentCategory << "]\n";
            std::cout << "--------------------------------------\n";
        }

        std::cout << "  - " << cmd->name()
                  << " -> " << cmd->description()
                  << "\n";
    }

    std::cout << "\n+--------------------------------------+\n";
}

// ===============================
// MAIN
// ===============================
int main()
{
    CommandRegistry registry;
    PluginLoader loader;

    std::vector<PluginHandle> loadedPlugins;
    std::vector<std::string> pluginNames;
    std::vector<std::string> history;

    size_t pluginCount = 0;
    size_t commandCount = 0;

    try
    {
        auto pluginRoot =
            std::filesystem::current_path() / "build" / "plugins";

        // ===============================
        // HEADER
        // ===============================
        std::cout <<
        "+--------------------------------------+\n"
        "| Dynamic Plugin Framework v1.0       |\n"
        "| Panel-Based Hybrid UI               |\n"
        "+--------------------------------------+\n\n";

        std::cout << "CWD        : " << std::filesystem::current_path() << "\n";
        std::cout << "PLUGIN DIR : " << pluginRoot << "\n\n";

        // ===============================
        // LOAD PLUGINS
        // ===============================
        for (const auto& entry :
             std::filesystem::recursive_directory_iterator(pluginRoot))
        {
            if (!entry.is_regular_file()) continue;
            if (entry.path().extension() != ".dll") continue;

            std::cout << "[LOAD] " << entry.path().stem().string() << "\n";

            try
            {
                auto plugin = loader.load(entry.path().string());

                if (!plugin.instance)
                {
                    std::cout << "[ERROR] Invalid plugin\n";
                    continue;
                }

                plugin.instance->initialize();

                auto commands = plugin.instance->createCommands();

                for (auto* cmd : commands)
                    registry.add(std::unique_ptr<ICommand>(cmd));

                loadedPlugins.push_back(std::move(plugin));

                pluginNames.push_back(entry.path().stem().string());
                pluginCount++;
                commandCount += commands.size();

                std::cout << "[OK] Loaded\n";
            }
            catch (const std::exception& ex)
            {
                std::cout << "[ERROR] " << ex.what() << "\n";
            }
        }

        if (loadedPlugins.empty())
        {
            std::cout << "[FATAL] No plugins loaded\n";
            return 1;
        }

        // ===============================
        // READY
        // ===============================
        std::cout <<
        "\n+--------------------------------------+\n"
        "|            SYSTEM READY             |\n"
        "+--------------------------------------+\n";

        std::cout << "Plugins : " << pluginCount << "\n";
        std::cout << "Commands: " << commandCount << "\n";

        // ===============================
        // MAIN LOOP (FIXED HYBRID SYSTEM)
        // ===============================
        while (true)
        {
            std::cout <<
            "\n+--------------------------------------+\n"
            "|         DPF CONTROL PANEL           |\n"
            "+--------------------------------------+\n"
            "| 1) Help                             |\n"
            "| 2) Plugins                          |\n"
            "| 3) Stats                            |\n"
            "| 4) History                          |\n"
            "| 5) Run Command                     |\n"
            "| 0) Exit                             |\n"
            "+--------------------------------------+\n"
            "Select / Command > ";

            std::string input;
            std::getline(std::cin, input);

            if (input.empty())
                continue;

            if (input == "0")
                break;

            // =========================
            // MENU MODE
            // =========================
            if (input == "1")
            {
                printHelp(registry);
                continue;
            }

            if (input == "2")
            {
                std::cout << "\n+ PLUGINS +\n";
                for (auto& p : pluginNames)
                    std::cout << " - " << p << "\n";
                continue;
            }

            if (input == "3")
            {
                std::cout << "\n+ STATS +\n";
                std::cout << "Plugins : " << pluginCount << "\n";
                std::cout << "Commands: " << commandCount << "\n";
                continue;
            }

            if (input == "4")
            {
                std::cout << "\n+ HISTORY +\n";
                for (size_t i = 0; i < history.size(); ++i)
                    std::cout << i + 1 << ". " << history[i] << "\n";
                continue;
            }

            if (input == "5")
            {
                std::cout << "Enter command > ";

                std::string cmdLine;
                std::getline(std::cin, cmdLine);

                if (!cmdLine.empty())
                {
                    history.push_back(cmdLine);
                    executeCommand(registry, cmdLine);
                }
                continue;
            }

            // =========================
            // DIRECT COMMAND MODE
            // =========================
            history.push_back(input);
            executeCommand(registry, input);
        }

        // ===============================
        // CLEANUP
        // ===============================
        for (auto& plugin : loadedPlugins)
        {
            plugin.instance->shutdown();
            loader.unload(plugin);
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << "[FATAL] " << ex.what() << "\n";
        return 1;
    }

    return 0;
}