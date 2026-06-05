cmake_minimum_required(VERSION 3.20)
project(UtilityModule)
file(GLOB UTILITY_SRC CONFIGURE_DEPENDS
    src/*.cpp)

add_library(UtilityModule SHARED ${UTILITY_SRC})

target_include_directories(UtilityModule PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/runtime/core)
target_link_libraries(UtilityModule PRIVATE runtime)

set_target_properties(UtilityModule PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/UtilityModule/Release
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/UtilityModule/Release
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins/UtilityModule/Release)
    
target_compile_features(UtilityModule PRIVATE cxx_std_17)