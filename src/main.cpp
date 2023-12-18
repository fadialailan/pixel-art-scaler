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
	cli_parse.setDefaultOutputFilenameFormat("{stem}X{resize_factor}{extension}");

	cli_parse.parse_inputs(argc, argv);

	int resize_factor = cli_parse.getResizeFactor();
	int grid_border_size = cli_parse.getGridBorderSize();
	std::vector<std::string> input_filenames = cli_parse.getInputFilenames();

	Magick::Color grid_color(cli_parse.getGridColor());

	for (std::string input_filename : input_filenames) {

		std::string output_filename = cli_parse.getFormatedOutputFilename(input_filename);

		ImageScaler image_scaler(input_filename);
		image_scaler.scale_image(resize_factor);
		image_scaler.add_grid(grid_border_size, resize_factor, grid_color);
		image_scaler.save_image(output_filename);
	}
}
