add_library(StringModule SHARED
    StringPlugin.cpp
    StringModule.cpp
    commands/UpperCommand.cpp
    commands/LowerCommand.cpp
    commands/LengthCommand.cpp
    commands/ConcatCommand.cpp
    commands/ReverseCommand.cpp
)

target_include_directories(StringModule PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ../../runtime
)