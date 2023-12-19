#ifndef IMAGE_SCALER_H
#define IMAGE_SCALER_H

#include "pch_magick++.hpp"
#include <memory>
#include <vector>

class ImageScaler {
      public:
	ImageScaler(std::string filename);
	~ImageScaler();
	void saveImage(std::string filename);
	void scaleImage(unsigned int scale_factor);
	void addGrid(unsigned int grid_border_size, unsigned int block_size,
		     Magick::Color grid_color);
	void scaleWithGrid(unsigned int scale_factor, unsigned int pixel_margin_size,
			   unsigned int block_size, Magick::Color grid_color);
	void fastSquare(unsigned int start_x, unsigned int start_y, unsigned int width,
			unsigned int height, Magick::Color color);

      private:
	std::shared_ptr<Magick::Image> image_object;
};

#endif
