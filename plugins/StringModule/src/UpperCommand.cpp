#include "UpperCommand.h"

std::string UpperCommand::name() const
{
    return "upper";
}

std::string UpperCommand::description() const
{
    return "Convert string to uppercase";
}

std::string UpperCommand::usage() const
{
    return "upper <text>";
}

RuntimeValue UpperCommand::execute(const std::vector<RuntimeValue>& args)
{
    std::string text = std::get<std::string>(args[0]);

    std::transform(
        text.begin(),
        text.end(),
        text.begin(),
        ::toupper
    );

    return text;
}