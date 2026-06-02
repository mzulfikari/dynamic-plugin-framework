#pragma once

#include "runtime/ICommand.h"

class DivCommand : public ICommand
{
public:

    std::string name() const override;

    std::string description() const override;

    int execute(
        const std::vector<int>& args
    ) override;
};