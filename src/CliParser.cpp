#include "CliParser.hpp"

CliParser::CliParser() {}

void CliParser::parse_inputs(int argc, char **argv) {

	CLI::App app = CLI::App("pixel resizer");
	app.add_option("--input,-i", this->input_filename, "the input file to resize")
	    ->required()
	    ->check(CLI::ExistingFile);
	app.add_option("--output,-o", this->output_filename, "where to save the output file")
	    ->required();

	app.add_option("--resize-factor", this->resize_factor, "the image's resize factor");
	app.add_option("--grid_size", this->grid_size, "the image's grid_size");

	try {
		app.parse((argc), (argv));
	} catch (const CLI::ParseError &e) {
		 exit(app.exit(e));
	}
}

void CliParser::setDefaultResizeFactor(int new_value) { this->resize_factor = new_value; }

void CliParser::setDefaultGridSize(int new_value) { this->grid_size = new_value; }

std::string CliParser::getInputFilename() { return this->input_filename; }

std::string CliParser::getOutputFilename() { return this->output_filename; }

int CliParser::getResizeFactor() { return this->resize_factor; }

int CliParser::getGridSize() { return this->grid_size; }
