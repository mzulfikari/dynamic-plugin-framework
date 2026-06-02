#pragma once

#include <string>
#include <unordered_map>

#include "runtime/PluginHandle.h"

class PluginRegistry
{
public:

    bool add(
        const std::string& name,
        const PluginHandle& plugin
    );

    bool contains(
        const std::string& name
    ) const;

    PluginHandle* find(
        const std::string& name
    );

    const PluginHandle* find(
        const std::string& name
    ) const;

    bool remove(
        const std::string& name
    );

    void clear();

    bool empty() const;

    std::size_t size() const;

    std::unordered_map<
        std::string,
        PluginHandle
    >& getAll();

    const std::unordered_map<
        std::string,
        PluginHandle
    >& getAll() const;

private:

    std::unordered_map<
        std::string,
        PluginHandle
    > plugins;
};