#include "ImageScaler.hpp"
#include <exception>
#include <iostream>

ImageScaler::ImageScaler(const char *filename) {

	this->image_object = std::make_unique<C_CImg>();
	try {
		this->image_object->load(filename);
	}
	/* catch (cimg_library::CImgException error) { */
	/* 	std::cerr << "error: " << error.what() << "\n"; */
	/* } */
	catch (std::exception error) {
		std::cerr << "error: " << error.what() << "\n";
	}
}

void ImageScaler::save_image(const char *filename) { this->image_object->save(filename); }

void ImageScaler::scale_image(uint scale_factor) {
	uint new_width = scale_factor * this->image_object->width();
	uint new_height = scale_factor * this->image_object->height();
	this->image_object->resize(new_width, new_height);
}

ImageScaler::~ImageScaler() {}
