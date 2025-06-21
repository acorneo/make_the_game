#pragma once

#include "ui/Button.hpp"
#include <raylib.h>
#include <vector>

#include "ui/Line.hpp"

class EngineApplication {
    // Those vectors are stuff that has to be rendered; normal people call it render pipeline
    std::vector<UI::Button> buttons_pipeline;
    std::vector<UI::Line> lines_pipeline;

    Font defaultFont = {};
public:
    void renderButtons(int zIdx);
    void renderLines(int zIdx);

    void init();
    void process();
    void close();
};
