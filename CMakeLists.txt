cmake_minimum_required(VERSION 3.17)
project(window_draw_test02)
#---------------------------------
#if(WIN32)
#        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#endif()
IF(FALSE)
    message(STATUS "USING A UNICODE")
    ADD_DEFINITIONS(-DUNICODE)
    ADD_DEFINITIONS(-D_UNICODE)
    ELSE()
    message(STATUS "NOT USING A UNICODE")
ENDIF()
#---------------------------------
message(STATUS "Set library prefix")
set( CMAKE_STATIC_LIBRARY_PREFIX "" )
#set( CMAKE_STATIC_LIBRARY_SUFFIX "" )
set( CMAKE_SHARED_LIBRARY_PREFIX "" )
#set( CMAKE_SHARED_LIBRARY_SUFFIX "" )
set( CMAKE_MODULE_LIBRARY_PREFIX "" )
#set( CMAKE_MODULE_LIBRARY_SUFFIX "" )
#---------------------------------
message(STATUS "Set main program env variable")
set(env_mainline_program WIN32)
set(env_mainprogram_header)
set(env_mainprogram_source
        main.cpp)
#---------------------------------
message(STATUS "Load sb_sandbox library")
add_subdirectory(sb_sandbox)
#---------------------------------
set( CMAKE_CXX_STANDARD 14 )
#---------------------------------
message(STATUS "Add main program or libraries")
add_executable(${PROJECT_NAME} ${env_mainline_program} ${env_mainprogram_header} ${env_mainprogram_source})
#---------------------------------
target_include_directories(${PROJECT_NAME} PRIVATE ${option_sb_sandbox_lib_header_directory})
target_link_libraries(${PROJECT_NAME} PRIVATE ${option_sb_sandbox_lib_name})
message(STATUS ${PROJECT_NAME}--PRIVATE--${option_sb_sandbox_lib_header_directory})
message(STATUS ${PROJECT_NAME}--PRIVATE--${option_sb_sandbox_lib_name})
#---------------------------------

