#include "SumListCommand.h"

std::string SumListCommand::name() const { return "sumlist"; }
std::string SumListCommand::description() const { return "sum all numbers"; }
std::string SumListCommand::usage() const { return "sumlist a b c ..."; }
std::string SumListCommand::category() const { return "numeric"; }

RuntimeValue SumListCommand::execute(const std::vector<RuntimeValue>& args)
{
    int sum = 0;

    for (const auto& arg : args)
    {
        sum += std::get<int>(arg);
    }

    return sum;
}