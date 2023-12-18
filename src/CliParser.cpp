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
	app.add_option("--grid-border-size", this->grid_border_size,
		       "the image's grid size (set to 0 to disable)");
	app.add_option("--grid-colour", this->grid_color, "the image's grid colour");

	try {
		app.parse((argc), (argv));
	} catch (const CLI::ParseError &e) {
		exit(app.exit(e));
	}
}

void CliParser::setDefaultResizeFactor(unsigned int new_value) { this->resize_factor = new_value; }

void CliParser::setDefaultGridBorderSize(unsigned int new_value) {
	this->grid_border_size = new_value;
}

void CliParser::setDefaultGridColor(std::string new_value) { this->grid_color = new_value; }

std::string CliParser::getInputFilename() { return this->input_filename; }

std::string CliParser::getOutputFilename() { return this->output_filename; }

unsigned int CliParser::getResizeFactor() { return this->resize_factor; }

unsigned int CliParser::getGridBorderSize() { return this->grid_border_size; }

std::string CliParser::getGridColor() { return this->grid_color; }

