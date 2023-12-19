#include "ImageScaler.hpp"
#include "fmt/core.h"
#include <exception>
#include <iostream>

ImageScaler::ImageScaler(std::string filename) : image_object{std::make_shared<Magick::Image>()} {

	try {
		this->image_object->read(filename);
	} catch (Magick::Error &error_data) {
		std::cerr << "error while reading the image: " << error_data.what() << "\n";
		exit(1);
	} catch (...) {
		std::cerr << "uncaught exception while reading the image\n";
		exit(2);
	}
	/* std::cout << "color space: " << this->image_object->quantizeColorSpace(); */
	fmt::println("channels: {}", this->image_object->channels());
}

void ImageScaler::saveImage(std::string filename) {

	try {
		this->image_object->write(filename);
	} catch (Magick::Error &error_data) {
		std::cerr << "error while writing the image: " << error_data.what() << "\n";
	} catch (...) {
		std::cerr << "uncaught exception while writing the image\n";
	}
}

void ImageScaler::scaleImage(uint scale_factor) {

	size_t width = this->image_object->columns();
	size_t height = this->image_object->rows();
	size_t new_width = width * scale_factor;
	size_t new_height = height * scale_factor;

	Magick::Geometry new_geometry{new_width, new_height};

	this->image_object->scale(Magick::Geometry(new_width, new_height));
}

void ImageScaler::addGrid(unsigned int grid_border_size, unsigned int block_size,
			  Magick::Color grid_color) {

	if (grid_border_size == 0) {
		return;
	}

	this->image_object->strokeColor(grid_color);
	this->image_object->fillColor(Magick::Color(0, 0, 0, QuantumRange));
	this->image_object->strokeWidth(grid_border_size);
	this->image_object->strokeAntiAlias(false);

	std::vector<Magick::Drawable> all_the_lines;

	size_t width = this->image_object->columns();
	size_t height = this->image_object->rows();
	size_t block_count_x = width / block_size;
	size_t block_count_y = height / block_size;

	for (int pixel_x = 0; pixel_x <= width; pixel_x += block_size) {
		all_the_lines.push_back(Magick::DrawableLine(pixel_x, 0, pixel_x, height - 1));
	}

	for (int pixel_y = 0; pixel_y <= height; pixel_y += block_size) {
		all_the_lines.push_back(Magick::DrawableLine(0, pixel_y, width - 1, pixel_y));
	}

	this->image_object->draw(all_the_lines);
}

void ImageScaler::scaleWithGrid(unsigned int scale_factor, unsigned int pixel_margin_size,
				unsigned int block_size, Magick::Color grid_color) {

	size_t width = this->image_object->columns();
	size_t height = this->image_object->rows();
	size_t new_width = (width + 1) * pixel_margin_size;
	size_t new_height = (height + 1) * pixel_margin_size;

	Magick::Image new_image(Magick::Geometry(new_width, new_height), grid_color);

	Magick::Pixels pixel_view(*this->image_object);
}

void ImageScaler::fastSquare(unsigned int start_x, unsigned int start_y, unsigned int width,
			     unsigned int height, Magick::Color color) {
	Quantum *pixel_cache = this->image_object->getPixels(start_x, start_y, width, height);
	size_t channel_count = this->image_object->channels();

	Quantum *current_quantum_pointer = pixel_cache;
	for (unsigned int x_coordinate = 0; x_coordinate < width; x_coordinate++) {
		for (unsigned int y_coordinate = 0; y_coordinate < width; y_coordinate++) {
			for (size_t current_channel = 0; current_channel < channel_count;
			     current_channel++) {
				if (current_channel == 0) {
					*current_quantum_pointer = color.quantumRed();
				} else if (current_channel == 1) {
					*current_quantum_pointer = color.quantumGreen();
				} else if (current_channel == 2) {
					*current_quantum_pointer = color.quantumBlue();
				} else if (current_channel == 3) {
					*current_quantum_pointer = color.quantumAlpha();
				}
				current_quantum_pointer++;
			}
		}
	}
}

ImageScaler::~ImageScaler() {}
