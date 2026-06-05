#include "MulCommand.h"
#include <variant>

std::string MulCommand::name() const { return "mul"; }

std::string MulCommand::description() const { return "multiply multiple numbers"; }

std::string MulCommand::category() const { return "numeric"; }

RuntimeValue MulCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return 0;

    bool found = false;
    int result = 1;

    for (const auto& arg : args)
    {
        if (std::holds_alternative<int>(arg))
        {
            int value = std::get<int>(arg);

            result *= value;
            found = true;
        }
    }

    if (!found)
        return 0;

    return result;
}