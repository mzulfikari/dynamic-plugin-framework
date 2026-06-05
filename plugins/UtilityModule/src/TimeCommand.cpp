#include "TimeCommand.h"
#include <chrono>
#include <ctime>

std::string TimeCommand::name() const { return "time"; }
std::string TimeCommand::description() const { return "current system time"; }
std::string TimeCommand::usage() const { return "time"; }
std::string TimeCommand::category() const { return "utility"; }

RuntimeValue TimeCommand::execute(const std::vector<RuntimeValue>& args)
{
    (void)args;

    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::string s = std::ctime(&t);

    if (!s.empty() && s.back() == '\n')
        s.pop_back();

    return s;
}