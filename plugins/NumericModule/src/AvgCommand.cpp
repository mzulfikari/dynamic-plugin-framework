#include "AvgCommand.h"
#include <variant>

std::string AvgCommand::name() const { return "avg"; }

std::string AvgCommand::description() const { return "calculate average of numbers"; }

std::string AvgCommand::category() const { return "numeric"; }

RuntimeValue AvgCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return 0;

    int sum = 0;
    int count = 0;

    for (const auto& arg : args)
    {
        if (std::holds_alternative<int>(arg))
        {
            sum += std::get<int>(arg);
            count++;
        }
    }

    if (count == 0)
        return 0;

    return sum / count;
}