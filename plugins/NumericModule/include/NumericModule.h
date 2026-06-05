#pragma once

#include "core/IPlugin.h"

class NumericModule : public IPlugin
{
public:
    bool initialize() override;
    void shutdown() override;

    std::vector<ICommand*> createCommands() override;
};