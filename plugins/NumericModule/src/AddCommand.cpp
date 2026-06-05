#include "AddCommand.h"
#include <stdexcept>

std::string AddCommand::name() const { return "add"; }
std::string AddCommand::description() const { return "add two numbers"; }
std::string AddCommand::category() const { return "numeric"; }

RuntimeValue AddCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2)
        return 0;

    if (!std::holds_alternative<int>(args[0]) ||
        !std::holds_alternative<int>(args[1]))
        return 0;

    int a = std::get<int>(args[0]);
    int b = std::get<int>(args[1]);

    return a + b;
}