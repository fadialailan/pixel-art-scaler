cmake_minimum_required(VERSION 3.20)

project(pixel-art-scaler VERSION 1.0
	DESCRIPTION "a program to scale pixel art and add a grid for visibilaty"
	LANGUAGES CXX)

add_executable(pixel-art-scaler src/main.cpp src/CliParser.cpp src/ImageScaler.cpp)

# find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
find_package(CLI11 REQUIRED)
find_package(PNG)
find_package(JPEG)
find_package(TIFF)

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

target_include_directories(pixel-art-scaler PUBLIC include ${JPEG_INCLUDE_DIRS} ${PNG_INCLUDE_DIRS} ${TIFF_INCLUDE_DIRS})
target_link_libraries(pixel-art-scaler CLI11::CLI11 m ${JPEG_LIBRARIES} ${PNG_LIBRARIES} ${TIFF_LIBRARIES})
target_precompile_headers(pixel-art-scaler PUBLIC include/pch_cimg.hpp)



