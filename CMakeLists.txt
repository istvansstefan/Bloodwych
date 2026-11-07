cmake_minimum_required(VERSION 3.25)

project(Bloodwych
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL3 CONFIG REQUIRED)

add_executable(Bloodwych
    src/main.cc
    src/dungeon/Dungeon.cc
    src/player/Player.cc
	src/rendering/SDL2DDungeonRenderer.cc
	src/rendering/SDL2DPlayerRenderer.cc
)

target_link_libraries(Bloodwych
    PRIVATE SDL3::SDL3
)

enable_testing()

add_executable(DungeonTests
    tests/DungeonTests.cc
    src/dungeon/Dungeon.cc
)

target_include_directories(DungeonTests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_test(
    NAME DungeonTests
    COMMAND DungeonTests
)
