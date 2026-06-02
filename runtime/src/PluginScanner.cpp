#include "runtime/PluginScanner.h"

#include <filesystem>

std::vector<std::string>
PluginScanner::scan(
    const std::string& directory
) const
{
    std::vector<std::string> plugins;

    namespace fs = std::filesystem;

    if (!fs::exists(directory))
    {
        return plugins;
    }

    for (const auto& entry
         : fs::directory_iterator(directory))
    {
        if (!entry.is_regular_file())
        {
            continue;
        }

        if (entry.path().extension() == ".dll")
        {
            plugins.push_back(
                entry.path().string()
            );
        }
    }

    return plugins;
}