#include "runtime/PluginLoader.h"

#include <windows.h>
#include <stdexcept>

#include "runtime/IPlugin.h"
#include "runtime/PluginFactory.h"

PluginHandle PluginLoader::load(const std::string& path)
{
    PluginHandle handle;

    return handle;
}

void PluginLoader::unload(PluginHandle& plugin)
{
}