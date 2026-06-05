#include "MinCommand.h"

std::string MinCommand::name() const { return "min"; }
std::string MinCommand::description() const { return "minimum value"; }
std::string MinCommand::usage() const { return "min a b c ..."; }
std::string MinCommand::category() const { return "numeric"; }

RuntimeValue MinCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return 0;

    int mn = std::get<int>(args[0]);

    for (size_t i = 1; i < args.size(); i++)
    {
        mn = std::min(mn, std::get<int>(args[i]));
    }

    return mn;
}