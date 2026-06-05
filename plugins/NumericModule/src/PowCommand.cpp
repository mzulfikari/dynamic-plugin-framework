#include "PowCommand.h"
#include <variant>
#include <cmath>

std::string PowCommand::name() const { return "pow"; }
std::string PowCommand::description() const { return "power function"; }
std::string PowCommand::usage() const { return "pow a b"; }
std::string PowCommand::category() const { return "numeric"; }

RuntimeValue PowCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2) return 0;

    return (int)std::pow(
        std::get<int>(args[0]),
        std::get<int>(args[1])
    );
}