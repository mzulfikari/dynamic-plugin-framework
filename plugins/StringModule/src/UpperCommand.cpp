#include "UpperCommand.h"
#include <algorithm>
#include <cctype>
#include <variant>

std::string UpperCommand::name() const { return "upper"; }

std::string UpperCommand::description() const { return "convert string to uppercase"; }

std::string UpperCommand::category() const { return "string"; }

RuntimeValue UpperCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return std::string("");

    if (!std::holds_alternative<std::string>(args[0]))
        return std::string("");

    std::string s = std::get<std::string>(args[0]);

    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return static_cast<char>(std::toupper(c)); });

    return s;
}