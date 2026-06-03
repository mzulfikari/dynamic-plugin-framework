#include <iostream>

#include "runtime/IPlugin.h"
#include "runtime/CommandRegistry.h"
#include "runtime/PluginLoader.h"

int main()
{
    CommandRegistry registry;
    PluginLoader loader;

    try
    {
        auto plugin = loader.load("D:/dynamic-plugin-framework/build/plugins/NumericModule/Release/NumericModule.dll");

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

        auto cmd = registry.find("add");

        if (!cmd)
        {
            std::cout << "Command not found\n";
            return 1;
        }

        std::cout << "2 + 3 = "
                  << cmd->execute({2, 3})
                  << '\n';

        plugin.instance->shutdown();

        loader.unload(plugin);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << '\n';
        return 1;
    }

    return 0;
}