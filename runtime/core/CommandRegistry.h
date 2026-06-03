#pragma once

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

#include "ICommand.h"

class CommandRegistry
{
public:
    void add(std::unique_ptr<ICommand> cmd);

    ICommand* find(const std::string& name);

    std::vector<std::string> list() const;

private:
    std::unordered_map<std::string, std::unique_ptr<ICommand>> commands;
};