#include "MulCommand.h"

std::string MulCommand::name() const
{
    return "mul";
}

std::string MulCommand::description() const
{
    return "Multiply two numbers";
}

int MulCommand::execute(const std::vector<int>& args)
{
    if (args.size() < 2)
        return 0;

    return args[0] * args[1];
}