#pragma once

#include "runtime/IPlugin.h"

class NumericModule : public IPlugin
{
public:

    PluginMetadata getMetadata() const override;

    bool initialize() override;

    void shutdown() override;

    int add(int a, int b) const;

    int subtract(int a, int b) const;

    int multiply(int a, int b) const;

    double divide(double a, double b) const;

private:

    bool initialized = false;
};