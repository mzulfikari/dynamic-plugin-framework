#include "SumListCommand.h"
#include <variant>

std::string SumListCommand::name() const { return "sumlist"; }

std::string SumListCommand::description() const { return "sum all integer values in list"; }

std::string SumListCommand::category() const { return "numeric"; }

RuntimeValue SumListCommand::execute(const std::vector<RuntimeValue>& args)
{
    int sum = 0;
    bool found = false;

    for (const auto& arg : args)
    {
        if (std::holds_alternative<int>(arg))
        {
            sum += std::get<int>(arg);
            found = true;
        }
    }

    if (!found)
        return 0;

    return sum;
}