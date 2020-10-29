// (C) 2020 christian@schladetsch.com

#include "GoRepo/TerminalColors.hpp"

namespace GoRepo {

std::map<Color, std::string> TerminalColors::Colors;

void TerminalColors::CreateColors() {
    Colors[Color::Red] = "0;31";
    Colors[Color::Green] = "0;32";
    Colors[Color::Blue] = "1;34";
    Colors[Color::LightGrey] = "0;37";
    Colors[Color::Bold] = "1";
    Colors[Color::Dim] = "2";
    Colors[Color::Italic] = "3";
    Colors[Color::Reset] = "0";
}

std::string TerminalColors::GetColorChange(Color color) {
    return "'\\033[" + Colors[color] + "m'";
}

}  // namespace GoRepo;
