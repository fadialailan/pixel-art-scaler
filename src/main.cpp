#include "CliParser.hpp"
#include "ImageScaler.hpp"
#include <Magick++.h>
#include <iostream>

int main(int argc, char **argv) {
	Magick::InitializeMagick(*argv);

	CliParser cli_parse = CliParser();

	cli_parse.setDefaultResizeFactor(20);
	cli_parse.setDefaultGridSize(0);

	cli_parse.parse_inputs(argc, argv);

	/* std::cout << "input filename: " << cli_parse.getInputFilename() << "\n"; */
	/* std::cout << "output filename: " << cli_parse.getOutputFilename() << "\n"; */
	/* std::cout << "grid size: " << cli_parse.getGridSize() << "\n"; */
	/* std::cout << "resize factor: " << cli_parse.getResizeFactor() << "\n"; */

	ImageScaler image_scaler(cli_parse.getInputFilename().c_str());

	image_scaler.scale_image(cli_parse.getResizeFactor());

	image_scaler.save_image(cli_parse.getOutputFilename().c_str());

	
}
