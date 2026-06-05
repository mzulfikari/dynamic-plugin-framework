#include "ContainsCommand.h"

std::string ContainsCommand::name() const { return "contains"; }
std::string ContainsCommand::description() const { return "check substring"; }
std::string ContainsCommand::usage() const { return "contains text sub"; }
std::string ContainsCommand::category() const { return "string"; }

RuntimeValue ContainsCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2) return 0;

    std::string s = std::get<std::string>(args[0]);
    std::string sub = std::get<std::string>(args[1]);

    return s.find(sub) != std::string::npos ? 1 : 0;
}