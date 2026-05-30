#pragma once

#include "PluginMetadata.h"

class IPlugin
{
public:

    virtual ~IPlugin() = default;

    virtual PluginMetadata getMetadata() const = 0;

    virtual bool initialize() = 0;

    virtual void shutdown() = 0;
};