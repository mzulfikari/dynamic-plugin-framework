#pragma once

#include <string>
#include <vector>

class ICommand
{
public:

    virtual ~ICommand() = default;

    virtual std::string getName() const = 0;

    virtual double execute(
        const std::vector<double>& args
    ) = 0;
};