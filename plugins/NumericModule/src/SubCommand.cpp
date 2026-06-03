#include "SubCommand.h"

#include <variant>

std::string SubCommand::name() const
{
    return "sub";
}

std::string SubCommand::description() const
{
    return "Subtract two numbers";
}

std::string SubCommand::usage() const
{
    return "sub <a> <b>";
}

RuntimeValue SubCommand::execute(
    const std::vector<RuntimeValue>& args
)
{
    if (args.size() < 2)
        return 0;

    int a = std::get<int>(args[0]);
    int b = std::get<int>(args[1]);

    return a - b;
}