#include "EchoCommand.h"

std::string EchoCommand::name() const { return "echo"; }
std::string EchoCommand::description() const { return "print input"; }
std::string EchoCommand::usage() const { return "echo text ..."; }
std::string EchoCommand::category() const { return "utility"; }

RuntimeValue EchoCommand::execute(const std::vector<RuntimeValue>& args)
{
    std::string result;

    for (const auto& arg : args)
    {
        if (!result.empty())
            result += " ";

        result += std::get<std::string>(arg);
    }

    return result;
}