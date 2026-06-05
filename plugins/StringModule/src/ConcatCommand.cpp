#include "ConcatCommand.h"
#include <variant>

std::string ConcatCommand::name() const { return "concat"; }

std::string ConcatCommand::description() const { return "concatenate multiple strings"; }

std::string ConcatCommand::category() const { return "string"; }

RuntimeValue ConcatCommand::execute(const std::vector<RuntimeValue>& args)
{
    std::string result;

    for (const auto& arg : args)
    {
        if (std::holds_alternative<std::string>(arg))
        {
            result += std::get<std::string>(arg);
        }
        else if (std::holds_alternative<int>(arg))
        {
            result += std::to_string(std::get<int>(arg));
        }
    }

    return result;
}