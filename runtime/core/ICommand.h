#pragma once

#include <string>
#include <vector>
#include "RuntimeValue.h"

class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual std::string name() const = 0;
    virtual std::string description() const = 0;
    virtual std::string usage() const = 0;

    virtual RuntimeValue execute(const std::vector<RuntimeValue>& args) = 0;
};