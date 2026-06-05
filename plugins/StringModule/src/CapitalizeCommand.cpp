#include "CapitalizeCommand.h"
#include <cctype>

std::string CapitalizeCommand::name() const { return "capitalize"; }
std::string CapitalizeCommand::description() const { return "capitalize first letter"; }
std::string CapitalizeCommand::usage() const { return "capitalize text"; }
std::string CapitalizeCommand::category() const { return "string"; }

RuntimeValue CapitalizeCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return std::string("");

    std::string s = std::get<std::string>(args[0]);

    if (!s.empty())
        s[0] = std::toupper(s[0]);

    return s;
}