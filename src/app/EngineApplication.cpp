#include "EngineApplication.h"
#include "raylib.h"

#include <iostream>

void EngineApplication::init() {
    InitWindow(800, 600, "make the game!");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    
    defaultFont = LoadFontEx("fonts/Roboto.ttf", 32, NULL, 0);
    SetTextureFilter(defaultFont.texture, TEXTURE_FILTER_BILINEAR);

    if (!IsFontValid(defaultFont)) {
        std::cerr << "Provided font is not available" << std::endl;
    }

    /* Just to test */
    Button btn {
        .width = 100,
        .height = 40,
        .xPos = 50,
        .yPos = 50,
        .backgroundColor = GetColor(0xFFFF00FF),
        .textColor = GetColor(0x000000FF),
        .text = "Example text"
    };

    buttons_pipeline.push_back(btn);
}

void EngineApplication::process() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (Button currentButton : buttons_pipeline) {
            int buttonFontSize = 16;

            Vector2 buttonTextSize = MeasureTextEx(defaultFont, currentButton.text.c_str(), buttonFontSize, 0.f);

            DrawRectangle(currentButton.xPos, currentButton.yPos,
                currentButton.width, currentButton.height,
                currentButton.backgroundColor);
            
            // void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint); // Draw text using font and additional parameters
            DrawTextEx(defaultFont, currentButton.text.c_str(), Vector2 {.x = (float)(currentButton.width-buttonTextSize.x) / 2 + currentButton.xPos, .y = (float)(currentButton.height - buttonTextSize.y) / 2 + currentButton.yPos}, buttonFontSize, 0.f, currentButton.textColor);
        }

        EndDrawing();
    }
}

void EngineApplication::close() {
    void close();
}