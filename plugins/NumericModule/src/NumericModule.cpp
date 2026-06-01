#include "NumericModule.h"
#include "PluginExports.h"

PluginMetadata NumericModule::getMetadata() const
{
    return {
        "NumericModule",
        "1.0.0",
        "Morteza",
        "Basic arithmetic operations plugin"
    };
}

bool NumericModule::initialize()
{
    initialized = true;
    return true;
}

void NumericModule::shutdown()
{
    initialized = false;
}

int NumericModule::add(int a, int b) const
{
    return a + b;
}

int NumericModule::subtract(int a, int b) const
{
    return a - b;
}

int NumericModule::multiply(int a, int b) const
{
    return a * b;
}

double NumericModule::divide(double a, double b) const
{
    return (b != 0) ? a / b : 0.0;
}

/* ===========================
   DLL Factory Functions
   =========================== */

PLUGIN_EXPORT IPlugin* CreatePlugin()
{
    return new NumericModule();
}

PLUGIN_EXPORT void DestroyPlugin(IPlugin* plugin)
{
    delete plugin;
}