#include <Magick++.h>
#include <memory>

class ImageScaler {
      public:
	ImageScaler(std::string filename);
	~ImageScaler();
	void save_image(std::string filename);
	void scale_image(unsigned int scale_factor);

      private:
	std::unique_ptr<Magick::Image> image_object;
};
