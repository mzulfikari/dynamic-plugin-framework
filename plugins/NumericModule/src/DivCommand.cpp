#include "DivCommand.h"
#include <variant>
#include <iostream>

std::string DivCommand::name() const { return "div"; }
std::string DivCommand::description() const { return "divide numbers"; }
std::string DivCommand::usage() const { return "div a b"; }
std::string DivCommand::category() const { return "numeric"; }

RuntimeValue DivCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2) return 0;

    int b = std::get<int>(args[1]);
    if (b == 0)
    {
        std::cerr << "Error: division by zero\n";
        return 0;
    }

    return std::get<int>(args[0]) / b;
}