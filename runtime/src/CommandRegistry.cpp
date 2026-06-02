#include "runtime/CommandRegistry.h"

void CommandRegistry::add(std::unique_ptr<ICommand> cmd)
{
    commands[cmd->name()] = std::move(cmd);
}

ICommand* CommandRegistry::find(const std::string& name)
{
    auto it = commands.find(name);

    if (it == commands.end())
    {
        return nullptr;
    }

    return it->second.get();
}