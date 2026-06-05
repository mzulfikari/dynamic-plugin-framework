#include "MaxCommand.h"

std::string MaxCommand::name() const { return "max"; }
std::string MaxCommand::description() const { return "maximum value"; }
std::string MaxCommand::usage() const { return "max a b c ..."; }
std::string MaxCommand::category() const { return "numeric"; }

RuntimeValue MaxCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return 0;

    int mx = std::get<int>(args[0]);

    for (size_t i = 1; i < args.size(); i++)
    {
        mx = std::max(mx, std::get<int>(args[i]));
    }

    return mx;
}