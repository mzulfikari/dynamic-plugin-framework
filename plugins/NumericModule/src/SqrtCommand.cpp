#include "SqrtCommand.h"
#include <variant>
#include <cmath>

std::string SqrtCommand::name() const { return "sqrt"; }

std::string SqrtCommand::description() const { return "square root of a number"; }

std::string SqrtCommand::category() const { return "numeric"; }

RuntimeValue SqrtCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return 0;

    if (!std::holds_alternative<int>(args[0]))
        return 0;

    int a = std::get<int>(args[0]);

    if (a < 0)
        return 0;

    int result = static_cast<int>(std::sqrt(a));

    return result;
}