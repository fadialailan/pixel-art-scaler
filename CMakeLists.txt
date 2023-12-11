cmake_minimum_required(VERSION 3.20)

project(pixel-art-scaler VERSION 1.0
	DESCRIPTION "a program to scale pixel art and add a grid for visibilaty"
	LANGUAGES CXX)

add_executable(pixel-art-scaler src/main.cpp)
target_include_directories(pixel-art-scaler PUBLIC include)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
	message(STATUS ">>> Linux")
	find_package(X11)
	target_link_libraries(pixel-art-scaler X11)
endif ()


