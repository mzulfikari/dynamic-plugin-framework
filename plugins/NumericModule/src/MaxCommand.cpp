#include "MaxCommand.h"
#include <variant>
#include <algorithm>

std::string MaxCommand::name() const { return "max"; }

std::string MaxCommand::description() const { return "maximum value from list of integers"; }

std::string MaxCommand::category() const { return "numeric"; }

RuntimeValue MaxCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return 0;

    bool found = false;
    int mx = 0;

    for (const auto& arg : args)
    {
        if (std::holds_alternative<int>(arg))
        {
            int value = std::get<int>(arg);

            if (!found)
            {
                mx = value;
                found = true;
            }
            else
            {
                mx = std::max(mx, value);
            }
        }
    }

    if (!found)
        return 0;

    return mx;
}