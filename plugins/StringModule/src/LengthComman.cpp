#include "LengthCommand.h"
#include <variant>

std::string LengthCommand::name() const { return "length"; }

std::string LengthCommand::description() const { return "get length of string"; }

std::string LengthCommand::category() const { return "string"; }

RuntimeValue LengthCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return 0;

    if (!std::holds_alternative<std::string>(args[0]))
        return 0;

    const std::string& s = std::get<std::string>(args[0]);

    return static_cast<int>(s.size());
}