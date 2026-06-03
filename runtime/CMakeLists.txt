add_library(runtime STATIC
    src/CommandRegistry.cpp
    src/PluginLoader.cpp
)

target_include_directories(runtime PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/core
)