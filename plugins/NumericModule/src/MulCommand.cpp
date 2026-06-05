#include "MulCommand.h"
#include <variant>

std::string MulCommand::name() const { return "mul"; }
std::string MulCommand::description() const { return "multiply numbers"; }
std::string MulCommand::usage() const { return "mul a b"; }
std::string MulCommand::category() const { return "numeric"; }

RuntimeValue MulCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2) return 0;

    return std::get<int>(args[0]) * std::get<int>(args[1]);
}