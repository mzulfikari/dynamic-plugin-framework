#include "AddCommand.h"
#include <variant>

std::string AddCommand::name() const { return "add"; }
std::string AddCommand::description() const { return "add two numbers"; }
std::string AddCommand::usage() const { return "add a b"; }
std::string AddCommand::category() const { return "numeric"; }

RuntimeValue AddCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2) return 0;

    return std::get<int>(args[0]) + std::get<int>(args[1]);
}