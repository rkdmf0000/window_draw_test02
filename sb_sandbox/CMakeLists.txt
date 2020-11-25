cmake_minimum_required(VERSION 3.17)
project(sb_sandbox)
#---------------------------------
message(STATUS "Set sb_sandbox program env variable")
#---------------------------------
set(sb_sandbox_lib_name sb_sandbox)
set(option_sb_sandbox_lib_name "${sb_sandbox_lib_name}" CACHE STRING "")
#---------------------------------
set(sb_sandbox_lib_header_directory
        ./sb_sandbox
        )
set(option_sb_sandbox_lib_header_directory "${sb_sandbox_lib_header_directory}" CACHE STRING "")
#---------------------------------
set(sb_sandbox_lib_header
        sb_define.h
        sb_sandbox.h
        )
#---------------------------------
set(sb_sandbox_lib_source
        sb_imp.cpp
        sb_env.cpp
        sb_sandbox.cpp
        sb_client.cpp
        sb_resource.cpp
        )
#---------------------------------
add_library(${PROJECT_NAME} STATIC ${sb_sandbox_lib_header} ${sb_sandbox_lib_source})


