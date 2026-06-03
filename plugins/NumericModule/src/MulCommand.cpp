#include "MulCommand.h"

#include <variant>

std::string MulCommand::name() const
{
    return "mul";
}

std::string MulCommand::description() const
{
    return "Multiply two numbers";
}

std::string MulCommand::usage() const
{
    return "mul <a> <b>";
}

RuntimeValue MulCommand::execute(
    const std::vector<RuntimeValue>& args
)
{
    if (args.size() < 2)
        return 0;

    int a = std::get<int>(args[0]);
    int b = std::get<int>(args[1]);

    return a * b;
}