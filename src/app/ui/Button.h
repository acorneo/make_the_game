#pragma once

#include <functional>
#include <raylib.h>
#include <string>

namespace UI {
    // Why is there no implementation?
    // Because creating .cpp file with rendering the specific button will be in absolutely different scope 
    // rather than in EngineApplication.cpp. It's all done for the sake of simplicity.
    // If project goes wild I will probably make super-duper OOP SOLID KISS AGILE GITHUB DOCKER implementation
    // but for now I would leave it like that.

    class Button {
    public:
        // no getters and setters today, java!!! :sob:
        int width {50};
        int height {25}; 
        int xPos {0};
        int yPos {0};
        Color backgroundColor {GetColor(0xFFFFFFFF)};
        bool outline {true};
        Color outlineColor {GetColor(0x000000FF)};
        int textSize {8};
        Color textColor {GetColor(0x000000FF)};
        std::string text {"Change me!"};
        bool textBold {false};
        std::function<void> *callback;
    };
};
