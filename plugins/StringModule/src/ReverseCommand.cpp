#include "ReverseCommand.h"
#include <algorithm>

std::string ReverseCommand::name() const { return "reverse"; }
std::string ReverseCommand::description() const { return "reverse string"; }
std::string ReverseCommand::usage() const { return "reverse text"; }
std::string ReverseCommand::category() const { return "string"; }

RuntimeValue ReverseCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return std::string("");

    std::string s = std::get<std::string>(args[0]);

    std::reverse(s.begin(), s.end());

    return s;
}