#pragma once

#include <functional>
#include <raylib.h>
#include <string>

class Button {
public:
    // no getters and setters today, java!!! :sob:
    int width {50};
    int height {25}; 
    int xPos {0};
    int yPos {0};
    Color backgroundColor {GetColor(0x808080FF)};
    int textSize {8};
    Color textColor {GetColor(0xFFFFFFFF)};
    std::string text {"Change me!"};
    bool textBold {false};
    std::function<void> *callback;
};