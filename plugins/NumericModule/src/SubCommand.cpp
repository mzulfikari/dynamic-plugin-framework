#include "SubCommand.h"
#include <variant>

std::string SubCommand::name() const { return "sub"; }
std::string SubCommand::description() const { return "subtract numbers"; }
std::string SubCommand::usage() const { return "sub a b"; }
std::string SubCommand::category() const { return "numeric"; }

RuntimeValue SubCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2) return 0;

    return std::get<int>(args[0]) - std::get<int>(args[1]);
}