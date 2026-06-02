#include "runtime/CommandRegistry.h"

bool CommandRegistry::add(
    std::unique_ptr<ICommand> command
)
{
    auto name =
        command->getName();

    return commands.emplace(
        name,
        std::move(command)
    ).second;
}

ICommand* CommandRegistry::find(
    const std::string& name
)
{
    auto it =
        commands.find(name);

    if (it == commands.end())
    {
        return nullptr;
    }

    return it->second.get();
}