cmake_minimum_required(VERSION 3.17)
project(window_draw_test02)
#---------------------------------
#if(WIN32)
#        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#endif()

IF(FALSE)
    ADD_DEFINITIONS(-DUNICODE)
    ADD_DEFINITIONS(-D_UNICODE)
    ELSE()
ENDIF()


#---------------------------------
set( CMAKE_STATIC_LIBRARY_PREFIX "" )
#set( CMAKE_STATIC_LIBRARY_SUFFIX "" )
set( CMAKE_SHARED_LIBRARY_PREFIX "" )
#set( CMAKE_SHARED_LIBRARY_SUFFIX "" )
set( CMAKE_MODULE_LIBRARY_PREFIX "" )
#set( CMAKE_MODULE_LIBRARY_SUFFIX "" )
#---------------------------------
set(env_mainline_program WIN32)
set(env_mainprogram_header)
set(env_mainprogram_source
        main.cpp)
#---------------------------------
set(sb_sandbox_lib_name sb_sandbox)
set(sb_sandbox_lib_header_directory ./sb_sandbox)
set(sb_sandbox_lib_header
        sb_sandbox/sb_sandbox.h)
set(sb_sandbox_lib_source
        sb_sandbox/sb_sandbox.cpp)
#---------------------------------
set( CMAKE_CXX_STANDARD 14 )
#---------------------------------
add_library(${sb_sandbox_lib_name} STATIC ${sb_sandbox_lib_header} ${sb_sandbox_lib_source})
add_executable(${PROJECT_NAME} ${env_mainline_program} ${env_mainprogram_header} ${env_mainprogram_source})
#---------------------------------
target_include_directories(${PROJECT_NAME} PRIVATE ${sb_sandbox_lib_header_directory})
target_link_libraries(${PROJECT_NAME} PRIVATE ${sb_sandbox_lib_name})
#---------------------------------
