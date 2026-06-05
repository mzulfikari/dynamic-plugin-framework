#include "SqrtCommand.h"
#include <cmath>

std::string SqrtCommand::name() const { return "sqrt"; }
std::string SqrtCommand::description() const { return "square root"; }
std::string SqrtCommand::usage() const { return "sqrt a"; }
std::string SqrtCommand::category() const { return "numeric"; }

RuntimeValue SqrtCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return 0;

    int a = std::get<int>(args[0]);
    return (int)std::sqrt(a);
}