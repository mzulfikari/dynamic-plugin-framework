#include "StringPlugin.h"

#include "UpperCommand.h"
#include "LowerCommand.h"
#include "LengthCommand.h"
#include "ConcatCommand.h"
#include "ReverseCommand.h"
#include "ContainsCommand.h"
#include "ReplaceCommand.h"
#include "SubstrCommand.h"
#include "CapitalizeCommand.h"

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

    cmds.push_back(new UpperCommand());
    cmds.push_back(new LowerCommand());

    cmds.push_back(new LengthCommand());
    cmds.push_back(new ConcatCommand());
    cmds.push_back(new ReverseCommand());

    cmds.push_back(new ContainsCommand());
    cmds.push_back(new ReplaceCommand());
    cmds.push_back(new SubstrCommand());

    cmds.push_back(new CapitalizeCommand());

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