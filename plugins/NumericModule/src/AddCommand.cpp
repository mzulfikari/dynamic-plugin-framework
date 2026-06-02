#include "AddCommand.h"

std::string AddCommand::name() const
{
    return "add";
}

std::string AddCommand::description() const
{
    return "Adds two numbers";
}

int AddCommand::execute(const std::vector<int>& args)
{
    return args[0] + args[1];
}