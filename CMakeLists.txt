cmake_minimum_required(VERSION 3.20)

project(dynamic_plugin_framework)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(runtime)
add_subdirectory(host)
add_subdirectory(plugins)