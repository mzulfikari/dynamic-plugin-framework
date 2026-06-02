#pragma once

#include <windows.h>

class IPlugin;

using CreatePluginFn = IPlugin* (*)();
using DestroyPluginFn = void(*)(IPlugin*);

struct PluginHandle
{
    HMODULE library = nullptr;
    IPlugin* instance = nullptr;
    DestroyPluginFn destroy = nullptr;
};