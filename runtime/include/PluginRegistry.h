#pragma once

#include <vector>
#include "PluginHandle.h"

class PluginRegistry
{
public:

    void add(const PluginHandle& plugin);

    const std::vector<PluginHandle>& getAll() const;

private:

    std::vector<PluginHandle> plugins;
};