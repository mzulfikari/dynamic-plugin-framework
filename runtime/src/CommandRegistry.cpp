#include "CommandRegistry.h"

void CommandRegistry::add(
    std::unique_ptr<ICommand> cmd
)
{
    commands[cmd->name()] =
        std::move(cmd);
}

ICommand* CommandRegistry::find(
    const std::string& name
)
{
    auto it =
        commands.find(name);

    if (it == commands.end())
        return nullptr;

    return it->second.get();
}

std::vector<std::string>
CommandRegistry::list() const
{
    std::vector<std::string> names;

    for (const auto& pair : commands)
    {
        names.push_back(
            pair.first
        );
    }

    return names;
}

std::unordered_map<
    std::string,
    std::vector<ICommand*>
>
CommandRegistry::groupedCommands() const
{
    std::unordered_map<
        std::string,
        std::vector<ICommand*>
    > groups;

    for (const auto& pair : commands)
    {
        ICommand* cmd =
            pair.second.get();

        groups[
            cmd->category()
        ].push_back(cmd);
    }

    return groups;
}