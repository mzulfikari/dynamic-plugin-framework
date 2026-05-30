#pragma once

#include <windows.h>
#include <memory>

class IPlugin;

struct PluginHandle
{
    HMODULE library = nullptr;

    IPlugin* instance = nullptr;
};