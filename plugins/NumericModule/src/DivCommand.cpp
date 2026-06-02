#include "DivCommand.h"

std::string DivCommand::name() const
{
    return "div";
}

std::string DivCommand::description() const
{
    return "Divide two numbers";
}

int DivCommand::execute(const std::vector<int>& args)
{
    if (args.size() < 2 || args[1] == 0)
        return 0;

    return args[0] / args[1];
}