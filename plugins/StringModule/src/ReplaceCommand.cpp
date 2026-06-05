#include "ReplaceCommand.h"

std::string ReplaceCommand::name() const { return "replace"; }
std::string ReplaceCommand::description() const { return "replace substring"; }
std::string ReplaceCommand::usage() const { return "replace text from to"; }
std::string ReplaceCommand::category() const { return "string"; }

RuntimeValue ReplaceCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 3) return std::string("");

    std::string s = std::get<std::string>(args[0]);
    std::string from = std::get<std::string>(args[1]);
    std::string to = std::get<std::string>(args[2]);

    size_t pos = s.find(from);

    if (pos != std::string::npos)
        s.replace(pos, from.size(), to);

    return s;
}