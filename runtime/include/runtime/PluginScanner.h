#pragma once

#include <string>
#include <vector>

class PluginScanner
{
public:

    std::vector<std::string> scan(
        const std::string& directory
    ) const;
};