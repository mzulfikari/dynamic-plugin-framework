#include "LengthCommand.h"

std::string LengthCommand::name() const { return "length"; }
std::string LengthCommand::description() const { return "string length"; }
std::string LengthCommand::usage() const { return "length text"; }
std::string LengthCommand::category() const { return "string"; }

RuntimeValue LengthCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return 0;

    const std::string& s = std::get<std::string>(args[0]);

    return (int)s.size();
}