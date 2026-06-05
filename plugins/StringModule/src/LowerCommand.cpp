#include "LowerCommand.h"
#include <algorithm>
#include <cctype>

std::string LowerCommand::name() const { return "lower"; }
std::string LowerCommand::description() const { return "convert to lowercase"; }
std::string LowerCommand::usage() const { return "lower text"; }
std::string LowerCommand::category() const { return "string"; }

RuntimeValue LowerCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return std::string("");

    std::string s = std::get<std::string>(args[0]);

    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); });

    return s;
}