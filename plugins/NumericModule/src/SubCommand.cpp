#include "SubCommand.h"

std::string SubCommand::name() const
{
    return "sub";
}

std::string SubCommand::description() const
{
    return "Subtract two numbers";
}

int SubCommand::execute(const std::vector<int>& args)
{
    if (args.size() < 2)
        return 0;

    return args[0] - args[1];
}