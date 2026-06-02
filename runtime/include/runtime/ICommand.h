#pragma once

#include <string>
#include <vector>

class ICommand
{
public:

    virtual ~ICommand() = default;

    virtual std::string name() const = 0;

    virtual std::string description() const = 0;

    virtual int execute(
        const std::vector<int>& args
    ) = 0;
};