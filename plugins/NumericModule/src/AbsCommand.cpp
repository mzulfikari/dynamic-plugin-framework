#include "AbsCommand.h"
#include <cstdlib>

std::string AbsCommand::name() const { return "abs"; }
std::string AbsCommand::description() const { return "absolute value"; }
std::string AbsCommand::usage() const { return "abs a"; }
std::string AbsCommand::category() const { return "numeric"; }

RuntimeValue AbsCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return 0;

    int a = std::get<int>(args[0]);
    return std::abs(a);
}