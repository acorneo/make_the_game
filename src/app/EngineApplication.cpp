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
    Button btn {};
    btn.width = 100;
    btn.textBold = true;

    buttons_pipeline.push_back(btn);
}

void EngineApplication::process() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (Button currentButton : buttons_pipeline) {
            int buttonFontSize = 16;
            Vector2 buttonTextSize = MeasureTextEx(defaultFont, currentButton.text.c_str(), buttonFontSize, 0.f);
            
            bool hovered = (GetMouseX() >= currentButton.xPos &&
                            GetMouseX() <= currentButton.xPos + currentButton.width &&
                            GetMouseY() >= currentButton.yPos &&
                            GetMouseY() <= currentButton.yPos + currentButton.height);
            
            bool mouseDown = IsMouseButtonDown(MOUSE_LEFT_BUTTON);

            if (hovered) {
                SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            } else {
                SetMouseCursor(MOUSE_CURSOR_ARROW);
            }

            if (mouseDown) {
                    Color hoverColor = currentButton.backgroundColor;
                    hoverColor.a = 0xEE;
                    DrawRectangle(currentButton.xPos, currentButton.yPos,
                        currentButton.width, currentButton.height,
                        hoverColor);
            }
            else {
                DrawRectangle(currentButton.xPos, currentButton.yPos,
                    currentButton.width, currentButton.height,
                    currentButton.backgroundColor);
            }
            
            // Drawing outline should only be after drawing the rectangle so it would be on the top
            if (currentButton.outline) {
                DrawRectangleLines(currentButton.xPos, currentButton.yPos, currentButton.width, currentButton.height, currentButton.outlineColor);
            }
            
            DrawTextEx(defaultFont, currentButton.text.c_str(),
            Vector2 {
                                .x = (float)(currentButton.width-buttonTextSize.x) / 2 + currentButton.xPos,
                                .y = (float)(currentButton.height - buttonTextSize.y) / 2 + currentButton.yPos
                              },
            buttonFontSize, 0.f, currentButton.textColor);

            // Create bold effect by create text dublicate 0.5pixels to the right
            if (currentButton.textBold) {
                DrawTextEx(defaultFont, currentButton.text.c_str(),
                Vector2 {
                                    .x = (float)(currentButton.width-buttonTextSize.x) / 2 + currentButton.xPos + 0.5f,
                                    .y = (float)(currentButton.height - buttonTextSize.y) / 2 + currentButton.yPos
                                },
                buttonFontSize, 0.f, currentButton.textColor);
            }
        }

        EndDrawing();
    }
}

void EngineApplication::close() {
    void close();
}