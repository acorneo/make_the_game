#include "EngineApplication.hpp"
#include "raylib.h"

#include <iostream>

void EngineApplication::init() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(800, 600, "make the game!");
    MaximizeWindow();
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    
    defaultFont = LoadFontEx("fonts/GNF.ttf", 32, NULL, 0);
    SetTextureFilter(defaultFont.texture, TEXTURE_FILTER_BILINEAR);

    if (!IsFontValid(defaultFont)) {
        std::cerr << "Provided font is not available" << std::endl;
    }

    /* Just to test */
    UI::Line line{
        .xStartPos = 0, .yStartPos = 0, .xEndPos = 200, .yEndPos = 200,
    };
    lines_pipeline.push_back(line);
}

void EngineApplication::process() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 5 layers overall
        for (int i = 0; i < 5; i++) {
            renderButtons(i);
            renderLines(i);
        }
        DrawFPS(GetScreenWidth()-100, GetScreenHeight()-100);

        EndDrawing();
    }
}

void EngineApplication::close() {
    void close();
}