#include "runtime/CommandRegistry.h"

bool CommandRegistry::add(std::unique_ptr<ICommand> cmd)
{
    if (!cmd)
        return false;

    const std::string name = cmd->name();

    if (commands.find(name) != commands.end())
        return false;

    commands.emplace(name, std::move(cmd));
    return true;
}

ICommand* CommandRegistry::find(const std::string& name) const
{
    auto it = commands.find(name);

    if (it == commands.end())
        return nullptr;

    return it->second.get();
}

std::vector<std::string> CommandRegistry::list() const
{
    std::vector<std::string> result;
    result.reserve(commands.size());

    for (const auto& [name, cmd] : commands)
        result.push_back(name);

    return result;
}