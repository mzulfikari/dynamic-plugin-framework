#pragma once

class IPlugin;

using CreatePluginFn = IPlugin* (*)();

using DestroyPluginFn = void (*)(IPlugin*);