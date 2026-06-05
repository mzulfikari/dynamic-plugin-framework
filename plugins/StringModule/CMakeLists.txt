add_library(StringModule SHARED
    src/StringPlugin.cpp
    src/UpperCommand.cpp
    src/LowerCommand.cpp
)

target_include_directories(StringModule PRIVATE
    ${CMAKE_SOURCE_DIR}/runtime
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(StringModule PRIVATE STRINGMODULE_EXPORTS)