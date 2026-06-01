add_executable(app
    src/main.cpp
)

target_include_directories(app
    PRIVATE
        ${PROJECT_SOURCE_DIR}/runtime/include
        ${PROJECT_SOURCE_DIR}/common/include
)

target_link_libraries(app
    PRIVATE
        runtime
)