cmake_minimum_required(VERSION 3.5) # So literally anyone would be able to compile
project(make_the_game)

find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/app/EngineApplication.h
    src/app/EngineApplication.cpp

    src/app/ui/Button.cpp
    src/app/ui/Button.h

    fonts/Roboto.ttf
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)