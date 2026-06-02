#pragma once

#include <vector>

#include "runtime/ICommand.h"

class IPlugin
{
public:
    virtual ~IPlugin() = default;

    virtual bool initialize() = 0;

    virtual void shutdown() = 0;

    virtual std::vector<ICommand*> createCommands() = 0;
};