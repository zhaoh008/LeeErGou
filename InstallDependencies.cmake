# InstallDependencies.cmake
file(GET_RUNTIME_DEPENDENCIES
        EXECUTABLES "D:/CPlusPlusProgram/LeeErGou/cmake-build-release/LeeErGou.exe"
        RESOLVED_DEPENDENCIES_VAR _r_deps
        UNRESOLVED_DEPENDENCIES_VAR _u_deps
        DIRECTORIES $ENV{PATH}
        PRE_EXCLUDE_REGEXES "api-ms-*" "ext-ms-*" "runtimeobject"
        POST_EXCLUDE_REGEXES ".*system32/.*\\.dll"
)

foreach(_file ${_r_deps})
    file(INSTALL
                DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
                TYPE SHARED_LIBRARY
                FOLLOW_SYMLINK_CHAIN
                FILES "${_file}"
    )
endforeach()

foreach(_file ${_u_deps})
    message(WARNING "Unresolved dependency: ${_file}")
endforeach()
