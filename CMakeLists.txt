cmake_minimum_required(VERSION 3.10)

project(console-bank)
set(CMAKE_CXX_STANDARD 17)

file (GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(include)
add_library(account SHARED ${SOURCES})
add_library(bank_system SHARED ${SOURCES})
target_include_directories(account PUBLIC include)
target_include_directories(bank_system PUBLIC include)

add_executable(main main.cpp)
target_link_libraries(main account)
target_link_libraries(main bank_system)