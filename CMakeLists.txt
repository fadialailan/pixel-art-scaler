cmake_minimum_required(VERSION 3.20)

project(pixel-art-scaler VERSION 1.0
	DESCRIPTION "a program to scale pixel art and add a grid for visibilaty"
	LANGUAGES CXX)

add_executable(pixel-art-scaler src/main.cpp src/CliParser.cpp)
target_include_directories(pixel-art-scaler PUBLIC include)

# find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
find_package(CLI11 REQUIRED)
target_link_libraries(pixel-art-scaler CLI11::CLI11 m)
# target_precompile_headers(pixel-art-scaler PUBLIC CImg.h)
target_precompile_headers(pixel-art-scaler PUBLIC include/pch_cimg.hpp)

# if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
# 	message(STATUS ">>> Linux")
# 	find_package(X11)
# 	target_link_libraries(pixel-art-scaler PRIVATE X11)
# endif ()



