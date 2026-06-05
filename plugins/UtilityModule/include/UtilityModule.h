#pragma once

#include <vector>

#include "IPlugin.h"
#include "core/ICommand.h"

class UtilityModule : public IPlugin
{
public:

    bool initialize() override;

    void shutdown() override;

    std::vector<ICommand*> createCommands() override;
};