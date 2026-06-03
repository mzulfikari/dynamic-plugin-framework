#include "AddCommand.h"

#include <stdexcept>

std::string AddCommand::name() const
{
    return "add";
}

std::string AddCommand::description() const
{
    return "Adds two integers";
}

std::string AddCommand::usage() const
{
    return "add <a> <b>";
}

RuntimeValue AddCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.size() < 2)
        throw std::runtime_error("add requires 2 arguments");

    int a = std::get<int>(args[0]);
    int b = std::get<int>(args[1]);

    return a + b;
}