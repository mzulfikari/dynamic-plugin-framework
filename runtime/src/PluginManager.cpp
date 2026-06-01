#include "runtime/PluginManager.h"

bool PluginManager::loadPlugin(
    const std::string& path
)
{
    return false;
}

bool PluginManager::unloadPlugin(
    const std::string& name
)
{
    return false;
}

void PluginManager::unloadAll()
{
}

const PluginRegistry& PluginManager::getRegistry() const
{
    return registry;
}