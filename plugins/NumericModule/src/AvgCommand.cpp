#include "AvgCommand.h"

std::string AvgCommand::name() const { return "avg"; }
std::string AvgCommand::description() const { return "average of numbers"; }
std::string AvgCommand::usage() const { return "avg a b c ..."; }
std::string AvgCommand::category() const { return "numeric"; }

RuntimeValue AvgCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return 0;

    int sum = 0;

    for (const auto& arg : args)
    {
        sum += std::get<int>(arg);
    }

    return sum / (int)args.size();
}