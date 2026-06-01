#include <iostream>

#include "runtime/PluginLoader.h"
#include "runtime/IPlugin.h"

int main()
{
    try
    {
        PluginLoader loader;

        PluginHandle plugin =
            loader.load("NumericModule.dll");

        auto metadata =
            plugin.instance->getMetadata();

        std::cout << "Plugin Loaded\n";
        std::cout << "Name: "
                  << metadata.name
                  << '\n';

        std::cout << "Version: "
                  << metadata.version
                  << '\n';

        std::cout << "Author: "
                  << metadata.author
                  << '\n';

        std::cout << "Description: "
                  << metadata.description
                  << '\n';

        loader.unload(plugin);

        std::cout << "\nPlugin Unloaded\n";
    }
    catch (const std::exception& ex)
    {
        std::cerr
            << "Error: "
            << ex.what()
            << '\n';
    }

    return 0;
}