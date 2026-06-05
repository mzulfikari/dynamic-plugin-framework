#include "ConcatCommand.h"

std::string ConcatCommand::name() const { return "concat"; }
std::string ConcatCommand::description() const { return "join strings"; }
std::string ConcatCommand::usage() const { return "concat a b c ..."; }
std::string ConcatCommand::category() const { return "string"; }

RuntimeValue ConcatCommand::execute(const std::vector<RuntimeValue>& args)
{
    std::string result;

    for (const auto& arg : args)
    {
        result += std::get<std::string>(arg);
    }

    return result;
}