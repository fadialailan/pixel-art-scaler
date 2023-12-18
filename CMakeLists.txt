cmake_minimum_required(VERSION 3.20)

project(pixel-art-scaler VERSION 1.0
	DESCRIPTION "a program to scale pixel art and add a grid for visibilaty"
	LANGUAGES CXX)

add_executable(pixel-art-scaler src/main.cpp src/CliParser.cpp src/ImageScaler.cpp)

find_package(CLI11 REQUIRED)
find_package(ImageMagick COMPONENTS Magick++ REQUIRED)
find_package(FMT REQUIRED)

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

target_include_directories(pixel-art-scaler PUBLIC include ${ImageMagick_INCLUDE_DIRS})
target_link_libraries(pixel-art-scaler PUBLIC CLI11::CLI11 fmt::fmt m ${ImageMagick_LIBRARIES})
target_precompile_headers(pixel-art-scaler PUBLIC include/pch_magick++.hpp)

# defines
target_compile_definitions(pixel-art-scaler PUBLIC MAGICKCORE_HDRI_ENABLE=1)
target_compile_definitions(pixel-art-scaler PUBLIC MAGICKCORE_QUANTUM_DEPTH=16)
target_compile_definitions(pixel-art-scaler PUBLIC MAGICKCORE_CHANNEL_MASK_DEPTH=32)


