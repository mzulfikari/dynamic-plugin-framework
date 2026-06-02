#include <iostream>

#include "runtime/PluginManager.h"
#include "runtime/IPlugin.h"

int main()
{
    PluginManager manager;

    if (!manager.loadPlugin("NumericModule.dll"))
    {
        std::cerr
            << "Failed to load plugin\n";

        return 1;
    }

    const auto& plugins =
        manager.getRegistry().getAll();

    for (const auto& [name, plugin] : plugins)
    {
        auto metadata =
            plugin.instance->getMetadata();

        std::cout << "Plugin Loaded\n";

        std::cout
            << "Name: "
            << metadata.name
            << '\n';

        std::cout
            << "Version: "
            << metadata.version
            << '\n';

        std::cout
            << "Author: "
            << metadata.author
            << '\n';

        std::cout
            << "Description: "
            << metadata.description
            << "\n\n";
    }

    manager.unloadAll();

    std::cout
        << "All Plugins Unloaded\n";

    return 0;
}