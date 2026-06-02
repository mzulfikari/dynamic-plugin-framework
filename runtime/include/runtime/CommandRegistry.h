#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "runtime/ICommand.h"

class CommandRegistry
{
public:

    bool add(
        std::unique_ptr<ICommand> command
    );

    ICommand* find(
        const std::string& name
    );

private:

    std::unordered_map<
        std::string,
        std::unique_ptr<ICommand>
    > commands;
};