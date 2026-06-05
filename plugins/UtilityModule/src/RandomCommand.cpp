#include "RandomCommand.h"
#include <random>

std::string RandomCommand::name() const { return "random"; }
std::string RandomCommand::description() const { return "generate random number"; }
std::string RandomCommand::category() const { return "utility"; }

RuntimeValue RandomCommand::execute(const std::vector<RuntimeValue>& args)
{
    int min = 0;
    int max = 9999999999;

    if (args.size() >= 2)
    {
        min = std::get<int>(args[0]);
        max = std::get<int>(args[1]);
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(min, max);

    return dist(gen);
}