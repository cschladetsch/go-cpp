// (C) 2020 christian@schladetsch.com

#pragma once

#include <map>
#include <string>

namespace GoRepo {

enum class Color {
    Red,
    Green,
    Blue,
    LightGrey,
    Dim,
    Bold,
    Italic,
    Reset,
};

class TerminalColors {
    static std::map<Color, std::string> Colors;

public:
    static void CreateColors();
    static std::string GetColorChange(Color color);
};

inline std::ostream& operator<<(std::ostream &out, Color color) {
    return out << TerminalColors::GetColorChange(color);
}

}  // namespace GoRepo

