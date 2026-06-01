#pragma once

#if defined(_WIN32)

    #define PLUGIN_EXPORT extern "C" __declspec(dllexport)

#else

    #define PLUGIN_EXPORT extern "C"

#endif