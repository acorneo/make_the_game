cmake_minimum_required(VERSION 3.5) # So literally anyone would be able to compile
project(make_the_game)

find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)