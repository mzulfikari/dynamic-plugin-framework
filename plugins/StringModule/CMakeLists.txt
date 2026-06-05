cmake_minimum_required(VERSION 3.20)
project(StringModule)

file(GLOB STRING_SRC CONFIGURE_DEPENDS
    src/*.cpp
)
add_library(StringModule SHARED ${STRING_SRC})
target_include_directories(StringModule PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/runtime/core
)
target_link_libraries(StringModule PRIVATE runtime)
set_target_properties(StringModule PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/StringModule
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/StringModule
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/StringModule
)
target_compile_features(StringModule PRIVATE cxx_std_17)