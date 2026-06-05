#pragma once

#include <vector>
#include <variant>

using RuntimeValue = std::variant<int, std::string>;

namespace NumericUtils
{
    inline std::vector<int> extractInts(
        const std::vector<RuntimeValue>& args
    )
    {
        std::vector<int> values;

        for (const auto& a : args)
        {
            if (std::holds_alternative<int>(a))
                values.push_back(std::get<int>(a));
        }

        return values;
    }
}