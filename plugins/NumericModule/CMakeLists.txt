add_library(NumericModule SHARED
    src/NumericModule.cpp
    src/AddCommand.cpp
    src/SubCommand.cpp
    src/MulCommand.cpp
    src/DivCommand.cpp
)

target_include_directories(NumericModule PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/core/include
)

target_link_libraries(NumericModule PRIVATE runtime)