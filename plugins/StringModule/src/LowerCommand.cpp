#include "LowerCommand.h"
#include <algorithm>
#include <cctype>

std::string LowerCommand::name() const { return "lower"; }

std::string LowerCommand::description() const { return "Convert string to lowercase"; }

std::string LowerCommand::usage() const { return "lower <text>"; }

RuntimeValue LowerCommand::execute(const std::vector<RuntimeValue>& args)
{
    std::string text = std::get<std::string>(args[0]);

    std::transform(text.begin(), text.end(), text.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return text;
}