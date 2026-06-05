#include "ContainsCommand.h"
#include <variant>

std::string ContainsCommand::name() const { return "contains"; }

std::string ContainsCommand::description() const { return "check if string contains substring"; }

std::string ContainsCommand::category() const { return "string"; }

RuntimeValue ContainsCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2)
        return 0;

    if (!std::holds_alternative<std::string>(args[0]) ||
        !std::holds_alternative<std::string>(args[1]))
    {
        return 0;
    }

    const std::string& s = std::get<std::string>(args[0]);
    const std::string& sub = std::get<std::string>(args[1]);

    return (s.find(sub) != std::string::npos) ? 1 : 0;
}