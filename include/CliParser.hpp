#ifndef CLI_PARSER_H
#define CLI_PARSER_H

#include <CLI/CLI.hpp>
#include <memory>

class CliParser {

      private:
	std::string input_filename;
	std::string output_filename;
	unsigned int resize_factor;
	unsigned int grid_border_size;
	std::string grid_color;

      public:
	CliParser();

	std::string getInputFilename();
	std::string getOutputFilename();
	unsigned int getResizeFactor();
	unsigned int getGridBorderSize();
	std::string getGridColor();

	void setDefaultResizeFactor(unsigned int new_value);
	void setDefaultGridBorderSize(unsigned int new_value);
	void setDefaultGridColor(std::string new_value);

	void parse_inputs(int argc, char **argv);
};

#endif
