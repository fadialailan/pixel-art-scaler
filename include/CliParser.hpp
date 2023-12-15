#include <CLI/CLI.hpp>
#include <memory>

class CliParser {

	private:
	std::string input_filename;
	std::string output_filename;
	uint resize_factor;
	uint grid_size;
	
	public:
	CliParser ();

	std::string getInputFilename();
	std::string getOutputFilename();
	uint getResizeFactor();
	uint getGridSize();

	void setDefaultResizeFactor(uint new_value);
	void setDefaultGridSize(uint new_value);
	
	void parse_inputs(int argc, char **argv);

};
