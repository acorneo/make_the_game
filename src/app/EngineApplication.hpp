#pragma once

#include "ui/Button.hpp"
#include <raylib.h>
#include <vector>

#include "ui/Line.hpp"

class EngineApplication {
    // Those vectors are stuff that has to be rendered; normal people call it render pipeline
    Font defaultFont = {};
    std::vector<UI::Button> buttons_pipeline;
    std::vector<UI::Line> lines_pipeline;

public:
    void renderButtons(int zIdx);
    void renderLines(int zIdx);

    void recalculate(); // it is totally not supposed to be inside this class, but otherwise I can't get access to pipelines

    void init();
    void process();
    void close();
};
