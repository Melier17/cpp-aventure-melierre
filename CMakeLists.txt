cmake_minimum_required(VERSION 3.11)
project(cpp_aventure_melierre)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)
