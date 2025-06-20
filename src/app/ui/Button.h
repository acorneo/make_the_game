#pragma once

#include <functional>
#include <raylib.h>
#include <string>

class Button {
public:
    // no getters and setters today, java!!! :sob:
    int width;
    int height; 
    int xPos;
    int yPos;
    Color backgroundColor;
    Color textColor;
    std::string text;
    std::function<void> *callback;
};