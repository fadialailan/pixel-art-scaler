#include "CliParser.hpp"

CliParser::CliParser() {}

void CliParser::parse_inputs(int argc, char **argv) {

	CLI::App app = CLI::App("pixel resizer");
	app.add_option("input-files", this->input_filenames, "the input file to resize")
	    ->required()
	    ->check(CLI::ExistingFile);
	app.add_option("--output,-o", this->output_filename_format,
		       "see output format section of the tutorial");

	app.add_option("--resize-factor", this->resize_factor, "the image's resize factor");
	app.add_option("--grid-border-size", this->grid_border_size,
		       "the image's grid size (set to 0 to disable)");
	app.add_option("--grid-color", this->grid_color, "the image's grid color");

	std::string grid_method_string;
	app.add_option("--grid-method", grid_method_string, "grid method [strokes, accurate]");
	CLI::IsMember(std::set({1, 2, 3}));

	try {
		app.parse((argc), (argv));
	} catch (const CLI::ParseError &e) {
		exit(app.exit(e));
	}

	std::optional<GridMethods::Value> grid_method_optional =
	    GridMethods::fromString(grid_method_string);
	if (!grid_method_optional.has_value()) {
		fmt::println(stderr, "invalid grid method \"{}\"", grid_method_string);
		exit(ERROR_PARSING_ARGUMENTS);
	}
	this->grid_method = grid_method_optional.value();
}

void CliParser::setDefaultResizeFactor(unsigned int new_value) { this->resize_factor = new_value; }

void CliParser::setDefaultGridBorderSize(unsigned int new_value) {
	this->grid_border_size = new_value;
}

void CliParser::setDefaultGridColor(std::string new_value) { this->grid_color = new_value; }
void CliParser::setDefaultOutputFilenameFormat(std::string new_value) {
	this->output_filename_format = new_value;
}

std::vector<std::string> CliParser::getInputFilenames() { return this->input_filenames; }

std::string CliParser::getOutputFilenameFormat() { return this->output_filename_format; }

unsigned int CliParser::getResizeFactor() { return this->resize_factor; }

unsigned int CliParser::getGridBorderSize() { return this->grid_border_size; }

std::string CliParser::getGridColor() { return this->grid_color; }

std::string CliParser::getFormatedOutputFilename(std::string input_filename) {

	std::filesystem::path input_path = input_filename;

	std::string output_filename =
	    fmt::format(this->output_filename_format, fmt::arg("stem", input_path.stem().string()),
			fmt::arg("extension", input_path.extension().string()),
			fmt::arg("resize_factor", resize_factor));

	return output_filename;
}
