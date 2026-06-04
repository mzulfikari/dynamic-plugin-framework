#pragma once

#include <vector>

class ICommand;

class IPlugin
{
public:
    virtual ~IPlugin() = default;

    virtual bool initialize() = 0;
    virtual void shutdown() = 0;

    virtual std::vector<ICommand*> createCommands() = 0;
};