#include <optional>

namespace GridMethods {
enum Value { strokes, accurate };

std::optional<Value> fromString(std::string);

} // namespace GridMethods
