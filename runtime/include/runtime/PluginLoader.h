#pragma once

#include <string>
#include "runtime/PluginHandle.h"

class PluginLoader
{
public:
    PluginHandle load(const std::string& path);
    void unload(PluginHandle& plugin);
};