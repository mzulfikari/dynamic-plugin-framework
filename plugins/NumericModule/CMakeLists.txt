cmake_minimum_required(VERSION 3.20)

project(NumericModule)


file(GLOB_RECURSE NUMERIC_SRC CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE NUMERIC_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)

add_library(NumericModule SHARED
    ${NUMERIC_SRC}
    ${NUMERIC_HEADERS}
)


target_include_directories(NumericModule PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/core/include
)


target_link_libraries(NumericModule PRIVATE runtime)


if (MSVC)
    target_compile_options(NumericModule PRIVATE /W3)
endif()