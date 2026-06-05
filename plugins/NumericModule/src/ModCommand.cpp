#include "ModCommand.h"
#include <stdexcept>

std::string ModCommand::name() const { return "mod"; }
std::string ModCommand::description() const { return "modulo operation"; }
std::string ModCommand::usage() const { return "mod a b"; }
std::string ModCommand::category() const { return "numeric"; }

RuntimeValue ModCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2) return 0;

    int a = std::get<int>(args[0]);
    int b = std::get<int>(args[1]);

    if (b == 0) return 0;

    return a % b;
}