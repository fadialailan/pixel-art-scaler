#include "pch_cimg.hpp"
#include "CliParser.hpp"
#include "ImageScaler.hpp"
#include <iostream>

#define DEBUG_LINE() std::cout << __FILE__ << ":" << __LINE__ << "\n"

int main(int argc, char **argv) {
	CliParser cli_parse = CliParser();

	cli_parse.setDefaultResizeFactor(20);
	cli_parse.setDefaultGridSize(0);

	cli_parse.parse_inputs(argc, argv);

	/* std::cout << "input filename: " << cli_parse.getInputFilename() << "\n"; */
	/* std::cout << "output filename: " << cli_parse.getOutputFilename() << "\n"; */
	/* std::cout << "grid size: " << cli_parse.getGridSize() << "\n"; */
	/* std::cout << "resize factor: " << cli_parse.getResizeFactor() << "\n"; */

	DEBUG_LINE();
	ImageScaler image_scaler(cli_parse.getInputFilename().c_str());
	/* std::cout << __FILE__ << ":" << __LINE__ << "\n" ; */
	DEBUG_LINE();

	image_scaler.scale_image(cli_parse.getResizeFactor());

	image_scaler.save_image(cli_parse.getOutputFilename().c_str());

	
}
