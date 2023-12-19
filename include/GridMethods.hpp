#pragma once

#include <optional>

namespace GridMethods {
enum Value { strokes, accurate };
const char strokes_string[] = "strokes";
const char accurate_string[] = "accurate";

std::optional<Value> fromString(std::string);

} // namespace GridMethods
