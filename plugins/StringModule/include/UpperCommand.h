#pragma once

#include "core/ICommand.h"
#include <algorithm>

class UpperCommand : public ICommand
{
public:
    std::string name() const override;
    std::string description() const override;
    std::string usage() const override;

    RuntimeValue execute(const std::vector<RuntimeValue>& args) override;
};