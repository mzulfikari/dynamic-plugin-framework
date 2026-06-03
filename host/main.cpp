#include <iostream>
#include <sstream>

#include "runtime/IPlugin.h"
#include "runtime/CommandRegistry.h"
#include "runtime/PluginLoader.h"

int main()
{
    CommandRegistry registry;
    PluginLoader loader;

    try
    {
        auto plugin = loader.load("../plugins/NumericModule/Release/NumericModule.dll");

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
        std::cout << "Type 'help' or 'list' to see commands\n";
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
                auto names = registry.list();

                std::cout << "Available commands:\n";

                for (const auto& n : names)
                    std::cout << "  " << n << "\n";

                continue;
            }

            std::stringstream ss(line);

            std::string cmdName;
            ss >> cmdName;

            if (cmdName.empty())
                continue;

            std::vector<int> args;
            int value;

            while (ss >> value)
                args.push_back(value);

            auto cmd = registry.find(cmdName);

            if (!cmd)
            {
                std::cout << "Command not found\n";
                continue;
            }

            std::cout << cmd->execute(args) << "\n";
        }

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