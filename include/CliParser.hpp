#pragma once

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

	std::vector<std::string> getInputFilenames() const;
	std::string getOutputFilenameFormat() const;
	unsigned int getResizeFactor() const;
	unsigned int getGridBorderSize() const;
	std::string getGridColor() const;
	GridMethods::Value getGridMethod() const;

	void setDefaultResizeFactor(unsigned int new_value);
	void setDefaultGridBorderSize(unsigned int new_value);
	void setDefaultGridColor(std::string new_value);
	void setDefaultOutputFilenameFormat(std::string new_value);
	void setDefaultGridMethod(GridMethods::Value new_value);
	

	void parse_inputs(int argc, char **argv);

	std::string getFormatedOutputFilename(std::string input_filename);
};

