#include "LowerCommand.h"
#include <algorithm>
#include <cctype>
#include <variant>

std::string LowerCommand::name() const { return "lower"; }

std::string LowerCommand::description() const { return "convert string to lowercase"; }

std::string LowerCommand::category() const { return "string"; }

RuntimeValue LowerCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return std::string("");

    if (!std::holds_alternative<std::string>(args[0]))
        return std::string("");

    std::string s = std::get<std::string>(args[0]);

    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });

    return s;
}