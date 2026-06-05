#include "FactCommand.h"

std::string FactCommand::name() const { return "fact"; }
std::string FactCommand::description() const { return "factorial"; }
std::string FactCommand::usage() const { return "fact n"; }
std::string FactCommand::category() const { return "numeric"; }

RuntimeValue FactCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty()) return 0;

    int n = std::get<int>(args[0]);

    if (n < 0) return 0;

    long long result = 1;

    for (int i = 2; i <= n; i++)
        result *= i;

    return (int)result;
}