cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_COMPILER "g++" )
set(CMAKE_C_COMPILER "gcc" )

project(flappy_bird)

set(SOURCE_FILES
	main.cpp
	./src/game.cpp
	./src/gameobject.cpp
	./src/pipe.cpp
	./src/player.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package (SFML 2.5 COMPONENTS graphics audio network REQUIRED)

target_link_libraries (${PROJECT_NAME} PUBLIC sfml-system sfml-graphics sfml-audio sfml-network)
