#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include <CLI/CLI.hpp>
#include <vector>
#include <memory>
#include <filesystem>
#include <fmt/core.h>
#include "GridMethods.hpp"
#include "error_codes.hpp"


class CliParser {

      private:
	//fields
	std::vector<std::string> input_filenames;
	std::string output_filename_format;
	unsigned int resize_factor;
	unsigned int grid_border_size;
	std::string grid_color;
	GridMethods::Value grid_method;

      public:
	CliParser();

	std::vector<std::string> getInputFilenames();
	std::string getOutputFilenameFormat();
	unsigned int getResizeFactor();
	unsigned int getGridBorderSize();
	std::string getGridColor();

	void setDefaultResizeFactor(unsigned int new_value);
	void setDefaultGridBorderSize(unsigned int new_value);
	void setDefaultGridColor(std::string new_value);
	void setDefaultOutputFilenameFormat(std::string new_value);

	void parse_inputs(int argc, char **argv);

	std::string getFormatedOutputFilename(std::string input_filename);
};

#endif
