#include "NumericModule.h"

#include "AddCommand.h"
#include "SubCommand.h"
#include "MulCommand.h"
#include "DivCommand.h"

bool NumericModule::initialize()
{
    initialized = true;
    return true;
}

void NumericModule::shutdown()
{
    initialized = false;
}

std::vector<ICommand*> NumericModule::createCommands()
{
    std::vector<ICommand*> commands;

    commands.push_back(new AddCommand());
    commands.push_back(new SubCommand());
    commands.push_back(new MulCommand());
    commands.push_back(new DivCommand());

    return commands;
}