#include "SubstrCommand.h"
#include <variant>

std::string SubstrCommand::name() const { return "substr"; }

std::string SubstrCommand::description() const { return "extract substring"; }

std::string SubstrCommand::category() const { return "string"; }

RuntimeValue SubstrCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 3)
        return std::string("");

    if (!std::holds_alternative<std::string>(args[0]) ||
        !std::holds_alternative<int>(args[1]) ||
        !std::holds_alternative<int>(args[2]))
    {
        return std::string("");
    }

    std::string s = std::get<std::string>(args[0]);
    int start = std::get<int>(args[1]);
    int len = std::get<int>(args[2]);

    if (start < 0 || start >= static_cast<int>(s.size()))
        return std::string("");

    if (len <= 0)
        return std::string("");

    if (start + len > static_cast<int>(s.size()))
        len = static_cast<int>(s.size()) - start;

    return s.substr(start, len);
}