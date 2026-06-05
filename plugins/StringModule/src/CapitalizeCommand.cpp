#include "CapitalizeCommand.h"
#include <variant>
#include <cctype>

std::string CapitalizeCommand::name() const { return "capitalize"; }

std::string CapitalizeCommand::description() const { return "capitalize first letter of string"; }

std::string CapitalizeCommand::category() const { return "string"; }

RuntimeValue CapitalizeCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return std::string("");

    if (!std::holds_alternative<std::string>(args[0]))
        return std::string("");

    std::string s = std::get<std::string>(args[0]);

    if (!s.empty())
        s[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));

    return s;
}