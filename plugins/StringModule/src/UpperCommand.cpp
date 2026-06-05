#include "UpperCommand.h"
#include <algorithm>
#include <cctype>

std::string UpperCommand::name() const { return "upper"; }
std::string UpperCommand::description() const { return "convert to uppercase"; }
std::string UpperCommand::usage() const { return "upper text"; }
std::string UpperCommand::category() const { return "string"; }

RuntimeValue UpperCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return std::string("");

    std::string s = std::get<std::string>(args[0]);

    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::toupper(c); });

    return s;
}