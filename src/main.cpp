#include "pch_cimg.h"
#include "CliParser.hpp"
#include <iostream>

int main(int argc, char **argv) {
	CliParser cli_parse = CliParser();

	cli_parse.setDefaultResizeFactor(20);
	cli_parse.setDefaultGridSize(1);

	cli_parse.parse_inputs(argc, argv);

	std::cout << "input filename: " << cli_parse.getInputFilename() << "\n";
	std::cout << "output filename: " << cli_parse.getOutputFilename() << "\n";
	std::cout << "grid size: " << cli_parse.getGridSize() << "\n";
	std::cout << "resize factor: " << cli_parse.getResizeFactor() << "\n";
}
