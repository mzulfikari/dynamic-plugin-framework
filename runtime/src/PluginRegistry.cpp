#include "runtime/PluginRegistry.h"

bool PluginRegistry::add(
    const std::string& name,
    const PluginHandle& plugin
)
{
    return plugins.emplace(
        name,
        plugin
    ).second;
}

bool PluginRegistry::contains(
    const std::string& name
) const
{
    return plugins.contains(name);
}

PluginHandle* PluginRegistry::find(
    const std::string& name
)
{
    auto it = plugins.find(name);

    if (it == plugins.end())
    {
        return nullptr;
    }

    return &it->second;
}

const PluginHandle* PluginRegistry::find(
    const std::string& name
) const
{
    auto it = plugins.find(name);

    if (it == plugins.end())
    {
        return nullptr;
    }

    return &it->second;
}

bool PluginRegistry::remove(
    const std::string& name
)
{
    return plugins.erase(name) > 0;
}

void PluginRegistry::clear()
{
    plugins.clear();
}

bool PluginRegistry::empty() const
{
    return plugins.empty();
}

std::size_t PluginRegistry::size() const
{
    return plugins.size();
}

const std::unordered_map<
    std::string,
    PluginHandle
>& PluginRegistry::getAll() const
{
    return plugins;
}