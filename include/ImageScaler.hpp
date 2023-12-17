#include <memory>
#include <Magick++.h>


class ImageScaler {
      public:
	ImageScaler(const char *filename);
	~ImageScaler();
	void save_image(const char *filename);
	void scale_image(unsigned int scale_factor);
};
