#include "PowCommand.h"
#include <variant>
#include <cmath>

std::string PowCommand::name() const { return "pow"; }

std::string PowCommand::description() const { return "power function (a^b)"; }

std::string PowCommand::category() const { return "numeric"; }

RuntimeValue PowCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2)
        return 0;

    if (!std::holds_alternative<int>(args[0]) ||
        !std::holds_alternative<int>(args[1]))
        return 0;

    int a = std::get<int>(args[0]);
    int b = std::get<int>(args[1]);

    double result = std::pow(a, b);

    return static_cast<int>(result);
}