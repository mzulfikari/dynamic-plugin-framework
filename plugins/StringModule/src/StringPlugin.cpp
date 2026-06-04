#include "StringPlugin.h"

#include "UpperCommand.h"
#include "LowerCommand.h"

bool StringPlugin::initialize()
{
    return true;
}

void StringPlugin::shutdown()
{
}

std::vector<ICommand*> StringPlugin::createCommands()
{
    std::vector<ICommand*> cmds;

    cmds.push_back(new UpperCommand());
    cmds.push_back(new LowerCommand());

    return cmds;
}