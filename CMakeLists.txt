cmake_minimum_required(VERSION 3.17)
project(GAMEINTERFACETEST)
#---------------------------------
#if(WIN32)
#        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#endif()

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

IF(FALSE)
    message(STATUS "USING A UNICODE")
    ADD_DEFINITIONS(-DUNICODE)
    ADD_DEFINITIONS(-D_UNICODE)
    ELSE()
    ADD_DEFINITIONS(-DMBCS)
    ADD_DEFINITIONS(-D_MBCS)
    message(STATUS "NOT USING A UNICODE")
ENDIF()

#find_library(GDIPLUS_LIBRARY NAMES libgdiplus gdiplus REQUIRED)



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

target_link_libraries(${PROJECT_NAME} PRIVATE gdiplus) #GDIPLUS - LINK


message(STATUS ${PROJECT_NAME}--PRIVATE--${option_sb_sandbox_lib_header_directory})
message(STATUS ${PROJECT_NAME}--PRIVATE--${option_sb_sandbox_lib_name})
#---------------------------------



