cmake_minimum_required(VERSION 3.5) # So literally anyone would be able to compile
project(make_the_game)

find_package(raylib REQUIRED)
file(COPY fonts DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME}
        src/main.cpp

        src/app/EngineApplication.hpp
        src/app/EngineApplication.cpp

        src/app/ui/Button.hpp
        src/app/ui/Line.hpp
        src/app/EngineRenderer.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)