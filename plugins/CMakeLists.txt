set(PLUGIN_MODULES
    NumericModule
    StringModule
    UtilityModule
)

foreach(module ${PLUGIN_MODULES})
    add_subdirectory(${module})
endforeach()