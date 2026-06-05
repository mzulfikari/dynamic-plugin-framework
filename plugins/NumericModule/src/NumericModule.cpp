#include "NumericModule.h"
#include "core/IPlugin.h"
#include "AddCommand.h"
#include "SubCommand.h"
#include "MulCommand.h"
#include "DivCommand.h"
#include "ModCommand.h"
#include "PowCommand.h"
#include "SqrtCommand.h"
#include "AbsCommand.h"
#include "MaxCommand.h"
#include "MinCommand.h"
#include "SumListCommand.h"
#include "AvgCommand.h"
#include "FactCommand.h"
#include "IsPrimeCommand.h"

bool NumericModule::initialize()
{
    return true;
}

void NumericModule::shutdown()
{
}

std::vector<ICommand*> NumericModule::createCommands()
{
    std::vector<ICommand*> cmds;

    cmds.reserve(14);

    cmds.push_back(new AddCommand());
    cmds.push_back(new SubCommand());
    cmds.push_back(new MulCommand());
    cmds.push_back(new DivCommand());
    cmds.push_back(new ModCommand());
    cmds.push_back(new PowCommand());
    cmds.push_back(new SqrtCommand());
    cmds.push_back(new AbsCommand());
    cmds.push_back(new MaxCommand());
    cmds.push_back(new MinCommand());
    cmds.push_back(new SumListCommand());
    cmds.push_back(new AvgCommand());
    cmds.push_back(new FactCommand());
    cmds.push_back(new IsPrimeCommand());

    return cmds;
}


extern "C" __declspec(dllexport)
IPlugin* CreatePlugin()
{
    return new NumericModule();
}