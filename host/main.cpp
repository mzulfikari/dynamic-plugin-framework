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
    std::cout << "\nAvailable commands:\n\n";

    auto names = registry.list();

    for (const auto& n : names)
    {
        auto cmd = registry.find(n);
        if (cmd)
        {
            std::cout << "  " << cmd->name()
                      << "\t" << cmd->description()
                      << "\n";
        }
    }

    std::cout << "\nUsage:\n";
    std::cout << "  host.exe --help\n";
    std::cout << "  host.exe list\n";
    std::cout << "  host.exe <command> [args]\n";
    std::cout << "  host.exe (interactive mode)\n\n";
}

int executeCommand(CommandRegistry& registry, const std::string& line)
{
    std::stringstream ss(line);

    std::string cmdName;
    ss >> cmdName;

    if (cmdName.empty())
        return 0;

    std::vector<RuntimeValue> args;
    int value;

    while (ss >> value)
        args.push_back(value);

    auto cmd = registry.find(cmdName);

    if (!cmd)
    {
        std::cout << "Command not found\n";
        return 1;
    }

    RuntimeValue result = cmd->execute(args);

    if (std::holds_alternative<int>(result))
    {
        std::cout << std::get<int>(result) << "\n";
    }
    else if (std::holds_alternative<std::string>(result))
    {
        std::cout << std::get<std::string>(result) << "\n";
    }

    return 0;
}

int main(int argc, char** argv)
{
    CommandRegistry registry;
    PluginLoader loader;

    try
    {
        // =========================
        // FIXED PLUGIN PATH
        // =========================
        std::filesystem::path pluginPath =
            std::filesystem::current_path()
            / "build"
            / "plugins"
            / "NumericModule"
            / "Release"
            / "NumericModule.dll";

        // =========================
        // DEBUG INFO
        // =========================
        std::cout << "=============================\n";
        std::cout << "PLUGIN DEBUG INFO\n";
        std::cout << "CWD: " << std::filesystem::current_path() << "\n";
        std::cout << "PLUGIN PATH: " << pluginPath << "\n";
        std::cout << "=============================\n";

        std::cout << "TRY LOAD: " << pluginPath.string() << "\n";

        // =========================
        // LOAD PLUGIN
        // =========================
        auto plugin = loader.load(pluginPath.string());

        if (!plugin.instance)
        {
            std::cout << "Plugin load failed\n";
            return 1;
        }

        plugin.instance->initialize();

        auto commands = plugin.instance->createCommands();

        for (auto& cmd : commands)
        {
            registry.add(std::unique_ptr<ICommand>(cmd));
        }

        std::cout << "Plugin loaded successfully\n";

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
                auto names = registry.list();

                for (const auto& n : names)
                    std::cout << n << "\n";

                return 0;
            }

            std::stringstream line;

            for (int i = 1; i < argc; i++)
                line << argv[i] << " ";

            return executeCommand(registry, line.str());
        }

        // =========================
        // REPL MODE
        // =========================
        std::cout << "\nType '--help' for commands\n";
        std::cout << "Type 'exit' to quit\n\n";

        while (true)
        {
            std::cout << "> ";
            std::string line;
            std::getline(std::cin, line);

            if (line == "exit")
                break;

            if (line == "help" || line == "list")
            {
                printHelp(registry);
                continue;
            }

            executeCommand(registry, line);
        }

        // =========================
        // CLEANUP
        // =========================
        plugin.instance->shutdown();
        loader.unload(plugin);
    }
    catch (const std::exception& ex)
    {
        std::cout << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}