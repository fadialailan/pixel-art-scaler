#include "ImageScaler.hpp"

ImageScaler::ImageScaler(const char* filename) {
	this->image_object = std::make_unique<C_CImg>(filename);
}

void ImageScaler::save_image(const char* filename) {
	this->image_object->save(filename);
}

void ImageScaler::scale_image(uint scale_factor) {
	this->image_object->resize(scale_factor * -100);
}

ImageScaler::~ImageScaler() {

}
