#include "ImageScaler.hpp"
#include <exception>
#include <iostream>

ImageScaler::ImageScaler(std::string filename) : image_object() {

	try {
		this->image_object.read(filename);
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
		this->image_object.write(filename);
	} catch (Magick::Error &error_data) {
		std::cerr << "error while writing the image: " << error_data.what() << "\n";
	} catch (...) {
		std::cerr << "uncaught exception while writing the image\n";
	}
}

void ImageScaler::scale_image(uint scale_factor) {

	size_t width = this->image_object.columns();
	size_t height = this->image_object.rows();
	size_t new_width = width * scale_factor;
	size_t new_height = height * scale_factor;

	Magick::Geometry new_geometry {new_width, new_height};

	this->image_object.scale(Magick::Geometry(new_width, new_height));
}

ImageScaler::~ImageScaler() {}
