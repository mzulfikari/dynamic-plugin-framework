#include "runtime/PluginLoader.h"
#include "runtime/PluginHandle.h"

#include <windows.h>
#include <iostream>
#include <stdexcept>

PluginHandle PluginLoader::load(const std::string& path)
{
    PluginHandle handle;

    std::cout << "TRY LOAD: " << path << std::endl;

    handle.library = LoadLibraryA(path.c_str());

    if (!handle.library)
    {
        DWORD error = GetLastError();
        std::cout << "LoadLibrary failed. Error: " << error << std::endl;
        throw std::runtime_error("Failed to load plugin library");
    }

    auto create =
        reinterpret_cast<CreatePluginFn>(
            GetProcAddress(handle.library, "CreatePlugin")
        );

    if (!create)
    {
        FreeLibrary(handle.library);
        throw std::runtime_error("CreatePlugin not found");
    }

    handle.instance = create();
    return handle;
}

void PluginLoader::unload(PluginHandle& plugin)
{
    if (!plugin.library)
        return;

    auto destroy =
        reinterpret_cast<DestroyPluginFn>(
            GetProcAddress(plugin.library, "DestroyPlugin")
        );

    if (destroy && plugin.instance)
    {
        destroy(plugin.instance);
    }

    FreeLibrary(plugin.library);

    plugin.library = nullptr;
    plugin.instance = nullptr;
}