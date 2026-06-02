#include "runtime/IPlugin.h"
#include "runtime/PluginManager.h"

bool PluginManager::loadPlugin(
    const std::string& path
)
{
    try
    {
        PluginHandle plugin =
            loader.load(path);

        auto metadata =
            plugin.instance->getMetadata();

        return registry.add(
            metadata.name,
            plugin
        );
    }
    catch (...)
    {
        return false;
    }
}

bool PluginManager::unloadPlugin(
    const std::string& name
)
{
    auto plugin =
        registry.find(name);

    if (!plugin)
    {
        return false;
    }

    loader.unload(*plugin);

    registry.remove(name);

    return true;
}

void PluginManager::unloadAll()
{
    for (auto& [name, plugin]
         : registry.getAll())
    {
        loader.unload(plugin);
    }

    registry.clear();
}

const PluginRegistry&
PluginManager::getRegistry() const
{
    return registry;
}