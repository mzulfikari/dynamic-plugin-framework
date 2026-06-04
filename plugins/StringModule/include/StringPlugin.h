#pragma once

#include "core/IPlugin.h"
#include <vector>

class StringPlugin : public IPlugin
{
public:
    bool initialize() override;
    void shutdown() override;

    std::vector<ICommand*> createCommands() override;
};