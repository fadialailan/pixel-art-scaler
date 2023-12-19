#include "ImageScaler.hpp"
#include "error_codes.hpp"
#include "fmt/core.h"
#include <exception>
#include <iostream>

ImageScaler::ImageScaler(std::string filename) : image_object{std::make_shared<Magick::Image>()} {

	try {
		this->image_object->read(filename);
	} catch (Magick::Error &error_data) {
		std::cerr << "error while reading the image: " << error_data.what() << "\n";
		exit(ERROR_READING_IMAGE);
	} catch (...) {
		std::cerr << "uncaught exception while reading the image\n";
		exit(ERROR_WRITING_IMAGE);
	}
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
				Magick::Color grid_color) {

	size_t width = this->image_object->columns();
	size_t height = this->image_object->rows();
	size_t new_width = (width + 1) * pixel_margin_size + (width * scale_factor);
	size_t new_height = (height + 1) * pixel_margin_size + (height * scale_factor);
	unsigned int block_size = scale_factor;

	std::shared_ptr<Magick::Image> old_image = this->image_object;

	this->image_object =
	    std::make_shared<Magick::Image>(Magick::Geometry(new_width, new_height), grid_color);

	this->image_object->strokeColor(Magick::Color(0,0,0, QuantumRange));
	for (unsigned int x_coordinate = 0; x_coordinate < width; x_coordinate++) {
		for (unsigned int y_coordinate = 0; y_coordinate < height; y_coordinate++) {
			unsigned int new_square_location_x =
			    pixel_margin_size + (scale_factor + pixel_margin_size) * x_coordinate;
			unsigned int new_square_location_y =
			    pixel_margin_size + (scale_factor + pixel_margin_size) * y_coordinate;

			Magick::Color pixel_color =
			    old_image->pixelColor(x_coordinate, y_coordinate);

			fastSquare(new_square_location_x, new_square_location_y, block_size,
				    block_size, pixel_color);
		}
	}
}

void ImageScaler::fastSquare(unsigned int start_x, unsigned int start_y, unsigned int width,
			      unsigned int height, Magick::Color color) {
	unsigned int max_x = width + start_x;
	unsigned int max_y = height + start_y;
	std::string color_string(color);
	for (unsigned int x_coordinate = start_x; x_coordinate < max_x; x_coordinate++) {
		for (unsigned int y_coordinate = start_y; y_coordinate < max_y; y_coordinate++) {
			this->image_object->pixelColor(x_coordinate, y_coordinate, color);
		}
	}
	this->image_object->syncPixels();
}

void ImageScaler::performScalingProcedure(GridMethods::Value grid_method, unsigned int scale_factor,
					  unsigned int grid_border_size, Magick::Color grid_color) {
	if (grid_border_size == 0) {
		this->scaleImage(scale_factor);
		return;
	}
	if (grid_method == GridMethods::strokes) {
		this->scaleImage(scale_factor);
		this->addGrid(grid_border_size, scale_factor, grid_color);
	} else if (grid_method == GridMethods::accurate) {
		this->scaleWithGrid(scale_factor, grid_border_size, grid_color);
	}
}

ImageScaler::~ImageScaler() {}
