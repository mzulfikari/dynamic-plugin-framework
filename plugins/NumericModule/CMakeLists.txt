add_library(NumericModule SHARED
    src/NumericModule.cpp
)

target_include_directories(NumericModule
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/runtime/include
        ${PROJECT_SOURCE_DIR}/common/include
)

set_target_properties(NumericModule PROPERTIES
    OUTPUT_NAME "NumericModule"
)