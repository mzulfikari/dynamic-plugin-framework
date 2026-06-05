#include "UtilityModule.h"

#include "EchoCommand.h"
#include "TimeCommand.h"
#include "RandomCommand.h"

bool UtilityModule::initialize()
{
    return true;
}

void UtilityModule::shutdown()
{
}

std::vector<ICommand*> UtilityModule::createCommands()
{
    std::vector<ICommand*> cmds;

    cmds.push_back(new EchoCommand());
    cmds.push_back(new TimeCommand());
    cmds.push_back(new RandomCommand());

    return cmds;
}

extern "C" __declspec(dllexport)
IPlugin* CreatePlugin()
{
    return new UtilityModule();
}

extern "C" __declspec(dllexport)
void DestroyPlugin(IPlugin* plugin)
{
    delete plugin;
}