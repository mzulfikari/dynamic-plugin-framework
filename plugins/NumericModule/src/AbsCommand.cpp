#include "AbsCommand.h"

std::string AbsCommand::name() const { return "abs"; }
std::string AbsCommand::description() const { return "absolute value"; }
std::string AbsCommand::category() const { return "numeric"; }

RuntimeValue AbsCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return 0;
    if (!std::holds_alternative<int>(args[0])) return 0;

    int x = std::get<int>(args[0]);
    return std::abs(x);
}