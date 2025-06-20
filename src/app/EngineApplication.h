#pragma once

#include "ui/Button.h"
#include <raylib.h>
#include <vector>

class EngineApplication {
private:
    // Those vectors are stuff that has to be rendered; normal people call it render pipeline
    std::vector<Button> buttons_pipeline;

    Font defaultFont;

public:
    void init();
    void process();
    void close();
};