#include "runtime/PluginLoader.h"

#include <windows.h>
#include <stdexcept>

#include "runtime/IPlugin.h"
#include "runtime/PluginFactory.h"

PluginHandle PluginLoader::load(const std::string& path)
{
    PluginHandle handle;

    handle.library = LoadLibraryA(path.c_str());

    if (!handle.library)
    {
        throw std::runtime_error(
            "Failed to load plugin library"
        );
    }

    auto create =
        reinterpret_cast<CreatePluginFn>(
            GetProcAddress(
                handle.library,
                "CreatePlugin"
            )
        );

    if (!create)
    {
        FreeLibrary(handle.library);

        throw std::runtime_error(
            "CreatePlugin export not found"
        );
    }

    handle.instance = create();

    return handle;
}

void PluginLoader::unload(PluginHandle& plugin)
{
    if (!plugin.library)
    {
        return;
    }

    auto destroy =
        reinterpret_cast<DestroyPluginFn>(
            GetProcAddress(
                plugin.library,
                "DestroyPlugin"
            )
        );

    if (destroy && plugin.instance)
    {
        destroy(plugin.instance);
    }

    FreeLibrary(plugin.library);

    plugin.library = nullptr;
    plugin.instance = nullptr;
}