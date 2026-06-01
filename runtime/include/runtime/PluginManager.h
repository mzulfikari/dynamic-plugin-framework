#pragma once

#include <string>

#include "runtime/PluginLoader.h"
#include "runtime/PluginRegistry.h"

class PluginManager
{
public:

    bool loadPlugin(
        const std::string& path
    );

    bool unloadPlugin(
        const std::string& name
    );

    void unloadAll();

    const PluginRegistry& getRegistry() const;

private:

    PluginLoader loader;

    PluginRegistry registry;
};