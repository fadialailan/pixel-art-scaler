#include "GridMethods.hpp"
#include "fmt/core.h"
#include <unordered_map>

namespace GridMethods {


std::optional<Value> fromString(std::string str) {
	
	if (str.compare("strokes") == 0) {
		return strokes;
	} else if (str.compare("accurate") == 0) {
		return accurate;
	}
	return std::nullopt;
}
} // namespace GridMethods
