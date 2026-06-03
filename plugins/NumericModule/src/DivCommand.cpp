#include "DivCommand.h"

#include <variant>

std::string DivCommand::name() const
{
    return "div";
}

std::string DivCommand::description() const
{
    return "Divide two numbers";
}

std::string DivCommand::usage() const
{
    return "div <a> <b>";
}

RuntimeValue DivCommand::execute(
    const std::vector<RuntimeValue>& args
)
{
    if (args.size() < 2)
        return 0;

    int a = std::get<int>(args[0]);
    int b = std::get<int>(args[1]);

    if (b == 0)
        return 0;

    return a / b;
}