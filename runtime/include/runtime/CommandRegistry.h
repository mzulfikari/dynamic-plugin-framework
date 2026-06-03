#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "runtime/ICommand.h"

class CommandRegistry
{
public:
    bool add(std::unique_ptr<ICommand> cmd);

    ICommand* find(const std::string& name) const;

    std::vector<std::string> list() const;

private:
    std::unordered_map<std::string, std::unique_ptr<ICommand>> commands;
};