#include "SubstrCommand.h"

std::string SubstrCommand::name() const { return "substr"; }
std::string SubstrCommand::description() const { return "substring"; }
std::string SubstrCommand::usage() const { return "substr text start length"; }
std::string SubstrCommand::category() const { return "string"; }

RuntimeValue SubstrCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 3) return std::string("");

    std::string s = std::get<std::string>(args[0]);
    int start = std::get<int>(args[1]);
    int len = std::get<int>(args[2]);

    if (start < 0 || start >= (int)s.size()) return std::string("");

    return s.substr(start, len);
}