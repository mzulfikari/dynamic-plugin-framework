#include "MinCommand.h"
#include <variant>
#include <algorithm>

std::string MinCommand::name() const { return "min"; }

std::string MinCommand::description() const { return "minimum value from list of integers"; }

std::string MinCommand::category() const { return "numeric"; }

RuntimeValue MinCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return 0;

    bool found = false;
    int mn = 0;

    for (const auto& arg : args)
    {
        if (std::holds_alternative<int>(arg))
        {
            int value = std::get<int>(arg);

            if (!found)
            {
                mn = value;
                found = true;
            }
            else
            {
                mn = std::min(mn, value);
            }
        }
    }

    if (!found)
        return 0;

    return mn;
}