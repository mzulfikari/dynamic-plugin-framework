add_library(runtime STATIC
    src/PluginLoader.cpp
    src/PluginManager.cpp
    src/PluginRegistry.cpp
)

target_include_directories(runtime
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(runtime
    PUBLIC
)

set_target_properties(runtime PROPERTIES
    OUTPUT_NAME "runtime"
)