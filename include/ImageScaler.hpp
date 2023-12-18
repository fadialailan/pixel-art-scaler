#ifndef IMAGE_SCALER_H
#define IMAGE_SCALER_H

#include "pch_magick++.hpp"
#include <memory>
#include <vector>

class ImageScaler {
      public:
	ImageScaler(std::string filename);
	~ImageScaler();
	void save_image(std::string filename);
	void scale_image(unsigned int scale_factor);
	void add_grid(unsigned int grid_border_size, unsigned int block_size, Magick::Color grid_color);

      private:
	std::unique_ptr<Magick::Image> image_object;
};

#endif
