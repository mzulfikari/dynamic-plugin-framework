add_library(NumericModule SHARED
    NumericPlugin.cpp
    AddCommand.cpp
    PluginExports.cpp
)

target_link_libraries(NumericModule PRIVATE runtime)

target_include_directories(NumericModule PRIVATE
    ../../runtime/include
)