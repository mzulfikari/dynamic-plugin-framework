#include "StringPlugin.h"

#include "UpperCommand.h"
#include "LowerCommand.h"

// ============================
// Plugin lifecycle
// ============================

bool StringPlugin::initialize()
{
    return true;
}

void StringPlugin::shutdown()
{
}

// ============================
// Commands factory
// ============================

std::vector<ICommand*> StringPlugin::createCommands()
{
    std::vector<ICommand*> cmds;
    cmds.reserve(2);

    cmds.push_back(new UpperCommand());
    cmds.push_back(new LowerCommand());

    return cmds;
}

// ============================
// DLL EXPORTS
// ============================

extern "C" __declspec(dllexport)
IPlugin* CreatePlugin()
{
    return new StringPlugin();
}

extern "C" __declspec(dllexport)
void DestroyPlugin(IPlugin* plugin)
{
    delete plugin;
}