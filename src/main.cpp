#include "CliParser.hpp"
#include "ImageScaler.hpp"
#include "pch_magick++.hpp"
#include <iostream>

int main(int argc, char **argv) {
	Magick::InitializeMagick(*argv);

	CliParser cli_parse = CliParser();

	cli_parse.setDefaultResizeFactor(20);
	cli_parse.setDefaultGridBorderSize(0);
	cli_parse.setDefaultGridColor("#0000ff");

	cli_parse.parse_inputs(argc, argv);

	/* std::cout << "input filename: " << cli_parse.getInputFilename() << "\n"; */
	/* std::cout << "output filename: " << cli_parse.getOutputFilename() << "\n"; */
	/* std::cout << "grid size: " << cli_parse.getGridSize() << "\n"; */
	/* std::cout << "resize factor: " << cli_parse.getResizeFactor() << "\n"; */


	int resize_factor = cli_parse.getResizeFactor();
	int grid_border_size = cli_parse.getGridBorderSize();
	std::string output_filename = cli_parse.getOutputFilename();
	std::string input_filename = cli_parse.getInputFilename();

	Magick::Color grid_color(cli_parse.getGridColor());

	ImageScaler image_scaler(input_filename);
	image_scaler.scale_image(resize_factor);
	image_scaler.add_grid(grid_border_size, resize_factor, grid_color);
	image_scaler.save_image(output_filename);


	
}
