#pragma once
#include <string>
#include "PluginHandle.h"   // ❗ full definition here
#include <string>

struct PluginHandle;

class PluginLoader
{
public:
    PluginHandle load(const std::string& path);
    void unload(PluginHandle& plugin);

};