cmake_minimum_required(VERSION 3.16)
project(winUI LANGUAGES CXX)

set(MINGW_PREFIX "C:/ProgramData/mingw64/mingw64/bin")

set(CMAKE_CXX_COMPILER "${MINGW_PREFIX}/g++.exe")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(SOURCE_FILES main.cpp)

add_executable(winUI WIN32 ${SOURCE_FILES})

target_compile_definitions(winUI PRIVATE UNICODE _UNICODE)
target_link_libraries(winUI PRIVATE kernel32 user32 gdi32)
