#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "runtime/ICommand.h"

class CommandRegistry
{
public:
    void add(std::unique_ptr<ICommand> cmd);

    ICommand* find(const std::string& name);

private:
    std::unordered_map<std::string, std::unique_ptr<ICommand>> commands;
};