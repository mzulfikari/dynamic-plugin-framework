#pragma once

#include "core/ICommand.h"

class SumListCommand : public ICommand
{
public:
    std::string name() const override;
    std::string description() const override;
    std::string category() const override;

    RuntimeValue execute(const std::vector<RuntimeValue>& args) override;
};