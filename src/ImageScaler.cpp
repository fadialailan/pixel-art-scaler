#include "ImageScaler.hpp"
#include <exception>
#include <iostream>

ImageScaler::ImageScaler(std::string filename) : image_object{std::make_unique<Magick::Image>()} {

	try {
		this->image_object->read(filename);
	} catch (Magick::Error &error_data) {
		std::cerr << "error while reading the image: " << error_data.what() << "\n";
		exit(1);
	} catch (...) {
		std::cerr << "uncaught exception while reading the image\n";
		exit(2);
	}
}

void ImageScaler::save_image(std::string filename) {

	try {
		this->image_object->write(filename);
	} catch (Magick::Error &error_data) {
		std::cerr << "error while writing the image: " << error_data.what() << "\n";
	} catch (...) {
		std::cerr << "uncaught exception while writing the image\n";
	}
}

void ImageScaler::scale_image(uint scale_factor) {

	size_t width = this->image_object->columns();
	size_t height = this->image_object->rows();
	size_t new_width = width * scale_factor;
	size_t new_height = height * scale_factor;

	Magick::Geometry new_geometry {new_width, new_height};

	this->image_object->scale(Magick::Geometry(new_width, new_height));
	
}

void ImageScaler::add_grid(unsigned int grid_border_size, unsigned int block_size, Magick::Color grid_color) {

	if (grid_border_size == 0) {
		return;
	}

	this->image_object->strokeColor(grid_color);
	this->image_object->fillColor(Magick::Color(0,0,0, QuantumRange));
	this->image_object->strokeWidth(grid_border_size);
	this->image_object->strokeAntiAlias(false);

	std::vector<Magick::Drawable> all_the_lines;

	size_t width = this->image_object->columns();
	size_t height = this->image_object->rows();
	size_t block_count_x = width / block_size;
	size_t block_count_y = height / block_size;

	
	for (int pixel_x = 0; pixel_x <= width; pixel_x += block_size) {
		all_the_lines.push_back(Magick::DrawableLine(pixel_x, 0, pixel_x,height-1));
	}

	for (int pixel_y = 0; pixel_y <= height; pixel_y += block_size) {
		all_the_lines.push_back(Magick::DrawableLine(0, pixel_y, width-1, pixel_y));
	}

	this->image_object->draw(all_the_lines);
}

ImageScaler::~ImageScaler() {}


