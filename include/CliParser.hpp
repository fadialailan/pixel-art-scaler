#include <CLI/CLI.hpp>
#include <memory>

class CliParser {

	private:
	std::string input_filename;
	std::string output_filename;
	int resize_factor;
	int grid_size;
	
	public:
	CliParser ();

	std::string getInputFilename();
	std::string getOutputFilename();
	int getResizeFactor();
	int getGridSize();

	void setDefaultResizeFactor(int new_value);
	void setDefaultGridSize(int new_value);
	
	void parse_inputs(int argc, char **argv);

};
