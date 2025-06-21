#include "EngineApplication.hpp"
#include "raylib.h"

#include <iostream>

// this namespace contains all the positions for engine UI elements
namespace eui {
    UI::Line fdivline_global;
    UI::Line sdivline_global;
    UI::Line upline;
    UI::Line downline;
    UI::Line leftline;
    UI::Line rightline;
};
// in case if window was resized, because it's adaptive interface
// I have to recalculate all ui elements positions
void EngineApplication::recalculate() {
    lines_pipeline.clear();
    buttons_pipeline.clear();

    float fdivline_global_xstps = 0.2f * static_cast<float>(GetScreenWidth());
    eui::fdivline_global.xStartPos = static_cast<int>(fdivline_global_xstps);
    eui::fdivline_global.xEndPos = eui::fdivline_global.xStartPos;
    eui::fdivline_global.yStartPos = 0;
    eui::fdivline_global.yEndPos = GetScreenHeight();
    lines_pipeline.push_back(eui::fdivline_global);

    float sdivline_global_xstps = 0.8f * static_cast<float>(GetScreenWidth());
    eui::sdivline_global.xStartPos = static_cast<int>(sdivline_global_xstps);
    eui::sdivline_global.xEndPos = eui::sdivline_global.xStartPos;
    eui::sdivline_global.yStartPos = 0;
    eui::sdivline_global.yEndPos = GetScreenHeight();
    lines_pipeline.push_back(eui::sdivline_global);

    eui::upline.xStartPos = 0;
    eui::upline.xEndPos = GetScreenWidth();
    eui::upline.yStartPos = 1;
    eui::upline.yEndPos = 1;
    lines_pipeline.push_back(eui::upline);

    eui::downline.xStartPos = 0;
    eui::downline.xEndPos = GetScreenWidth();
    eui::downline.yStartPos = GetScreenHeight()-2;
    eui::downline.yEndPos = GetScreenHeight()-2;
    lines_pipeline.push_back(eui::downline);

    eui::leftline.xStartPos = 2;
    eui::leftline.xEndPos = 2;
    eui::leftline.yStartPos = 0;
    eui::leftline.yEndPos = GetScreenHeight();
    lines_pipeline.push_back(eui::leftline);

    eui::rightline.xStartPos = GetScreenWidth()-1;
    eui::rightline.xEndPos = GetScreenWidth()-1;
    eui::rightline.yStartPos = 0;
    eui::rightline.yEndPos = GetScreenHeight();
    lines_pipeline.push_back(eui::rightline);
}

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

    recalculate();
}

void EngineApplication::process() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (IsWindowResized()) {
            recalculate();
        }

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