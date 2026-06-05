#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <variant>
#include <filesystem>

#include "core/IPlugin.h"
#include "core/CommandRegistry.h"
#include "core/PluginLoader.h"

void printHelp(CommandRegistry& registry)
{
    std::cout << "\n==============================\n";
    std::cout << "        AVAILABLE COMMANDS     \n";
    std::cout << "==============================\n\n";

    auto names = registry.list();

    std::string currentCategory;

    for (const auto& n : names)
    {
        auto cmd = registry.find(n);
        if (!cmd) continue;

        // دسته‌بندی تمیز
        if (cmd->category() != currentCategory)
        {
            currentCategory = cmd->category();

            std::cout << "\n[" << currentCategory << "]\n";
            std::cout << "------------------------------\n";
        }

        std::cout
            << "  "
            << cmd->name()
            << "  ->  "
            << cmd->description()
            << "\n";
    }

    std::cout << "\n==============================\n";
    std::cout << "Usage:\n";
    std::cout << "  host.exe <command> [args]\n";
    std::cout << "  host.exe list\n";
    std::cout << "  host.exe --help\n";
    std::cout << "  interactive mode (no args)\n";
    std::cout << "==============================\n\n";
}

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

int executeCommand(
    CommandRegistry& registry,
    const std::string& line)
{
    std::stringstream ss(line);

    std::string cmdName;
    ss >> cmdName;

    if (cmdName.empty())
        return 0;

    std::vector<RuntimeValue> args;
    std::string token;

    while (ss >> token)
    {
        args.push_back(parseToken(token));
    }

    auto cmd = registry.find(cmdName);

    if (!cmd)
    {
        std::cout << "❌ Command not found: " << cmdName << "\n";
        return 1;
    }

    try
    {
        RuntimeValue result = cmd->execute(args);

        if (std::holds_alternative<int>(result))
        {
            std::cout << std::get<int>(result) << "\n";
        }
        else if (std::holds_alternative<std::string>(result))
        {
            std::cout << std::get<std::string>(result) << "\n";
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << "❌ Execution error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}

int main(int argc, char** argv)
{
    CommandRegistry registry;
    PluginLoader loader;

    std::vector<PluginHandle> loadedPlugins;

    try
    {
        std::filesystem::path pluginRoot =
            std::filesystem::current_path() / "build" / "plugins";

        std::cout << "=============================\n";
        std::cout << "  DYNAMIC PLUGIN FRAMEWORK\n";
        std::cout << "=============================\n";

        std::cout << "CWD        : " << std::filesystem::current_path() << "\n";
        std::cout << "PLUGIN DIR : " << pluginRoot << "\n";
        std::cout << "=============================\n\n";

        // =========================
        // LOAD PLUGINS
        // =========================
        for (const auto& entry :
             std::filesystem::recursive_directory_iterator(pluginRoot))
        {
            if (!entry.is_regular_file())
                continue;

            if (entry.path().extension() != ".dll")
                continue;

            std::cout << "Loading: " << entry.path().filename().string() << "\n";

            try
            {
                auto plugin = loader.load(entry.path().string());

                if (!plugin.instance)
                {
                    std::cout << "❌ Invalid plugin\n";
                    continue;
                }

                plugin.instance->initialize();

                auto commands = plugin.instance->createCommands();

                for (auto* cmd : commands)
                {
                    registry.add(std::unique_ptr<ICommand>(cmd));
                }

                loadedPlugins.push_back(std::move(plugin));

                std::cout << "✅ Loaded\n";
            }
            catch (const std::exception& ex)
            {
                std::cout << "❌ Failed: " << ex.what() << "\n";
            }
        }

        if (loadedPlugins.empty())
        {
            std::cout << "❌ No plugins loaded\n";
            return 1;
        }

        // =========================
        // CLI MODE
        // =========================
        if (argc > 1)
        {
            std::string arg1 = argv[1];

            if (arg1 == "--help" || arg1 == "help")
            {
                printHelp(registry);
                return 0;
            }

            if (arg1 == "list")
            {
                for (const auto& n : registry.list())
                    std::cout << n << "\n";

                return 0;
            }

            std::stringstream line;
            for (int i = 1; i < argc; ++i)
                line << argv[i] << " ";

            return executeCommand(registry, line.str());
        }

        // =========================
        // INTERACTIVE MODE
        // =========================
        std::cout << "\nType 'help' for commands\n";
        std::cout << "Type 'exit' to quit\n\n";

        while (true)
        {
            std::cout << "> ";

            std::string line;
            std::getline(std::cin, line);

            if (line == "exit")
                break;

            if (line == "help")
            {
                printHelp(registry);
                continue;
            }

            if (line == "list")
            {
                for (const auto& n : registry.list())
                    std::cout << n << "\n";

                continue;
            }

            executeCommand(registry, line);
        }

        // =========================
        // CLEANUP
        // =========================
        for (auto& plugin : loadedPlugins)
        {
            plugin.instance->shutdown();
            loader.unload(plugin);
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << "Fatal error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}