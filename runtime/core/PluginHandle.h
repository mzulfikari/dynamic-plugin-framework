#pragma once

#include <windows.h>
#include "IPlugin.h"

using CreatePluginFn = IPlugin* (*)();
using DestroyPluginFn = void(*)(IPlugin*);

struct PluginHandle
{
    HMODULE library = nullptr;
    IPlugin* instance = nullptr;
    DestroyPluginFn destroy = nullptr;
};