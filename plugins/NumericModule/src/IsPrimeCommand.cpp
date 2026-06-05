#include "IsPrimeCommand.h"
#include <variant>
#include <cmath>

std::string IsPrimeCommand::name() const { return "isprime"; }

std::string IsPrimeCommand::description() const { return "check if number is prime"; }

std::string IsPrimeCommand::category() const { return "numeric"; }

RuntimeValue IsPrimeCommand::execute(const std::vector<RuntimeValue>& args)
{
    if (args.empty())
        return 0;

    if (!std::holds_alternative<int>(args[0]))
        return 0;

    int n = std::get<int>(args[0]);

    if (n <= 1)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    int limit = static_cast<int>(std::sqrt(n));

    for (int i = 3; i <= limit; i += 2)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}