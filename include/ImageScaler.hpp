#include "pch_cimg.hpp"
#include <memory>

typedef cimg_library::CImg<u_int8_t> C_CImg;

class ImageScaler {
      public:
	ImageScaler(const char *filename);
	~ImageScaler();
	void save_image(const char *filename);
	void scale_image(uint scale_factor);

      private:
	std::unique_ptr<C_CImg> image_object;
};
