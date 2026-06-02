#pragma once

#include "runtime/IPlugin.h"

class NumericModule : public IPlugin
{
public:
    bool initialize() override;
    void shutdown() override;

    std::vector<ICommand*> createCommands() override;

private:
    bool initialized = false;
};