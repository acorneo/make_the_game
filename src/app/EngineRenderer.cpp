//
// Created by max on 6/21/25.
//

#include "EngineApplication.hpp"

void EngineApplication::renderButtons(int zIdx) {
    for (const UI::Button &currentButton: buttons_pipeline) {
        if (currentButton.zIndex != zIdx) continue;

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

        if (mouseDown && hovered) {
            Color hoverColor = currentButton.backgroundColor;
            hoverColor.a = 0x99;
            DrawRectangle(currentButton.xPos, currentButton.yPos,
                          currentButton.width, currentButton.height,
                          hoverColor);
        } else {
            DrawRectangle(currentButton.xPos, currentButton.yPos,
                          currentButton.width, currentButton.height,
                          currentButton.backgroundColor);
        }

        if (currentButton.outline) {
            // And now draw pixel effect
            DrawRectangle(currentButton.xPos - 3, currentButton.yPos, 3, currentButton.height,
                          currentButton.outlineColor);
            DrawRectangle(currentButton.xPos + currentButton.width, currentButton.yPos, 3, currentButton.height,
                          currentButton.outlineColor);
            DrawRectangle(currentButton.xPos, currentButton.yPos - 3, currentButton.width, 3,
                          currentButton.outlineColor);
            DrawRectangle(currentButton.xPos, currentButton.yPos + currentButton.height, currentButton.width, 3,
                          currentButton.outlineColor);
        }

        DrawTextEx(defaultFont, currentButton.text.c_str(),
                   Vector2{
                       .x = (float) (currentButton.width - buttonTextSize.x) / 2 + currentButton.xPos,
                       .y = (float) (currentButton.height - buttonTextSize.y) / 2 + currentButton.yPos
                   },
                   buttonFontSize, 0.f, currentButton.textColor);

        // Create bold effect by create text dublicate 0.5pixels to the right
        if (currentButton.textBold) {
            DrawTextEx(defaultFont, currentButton.text.c_str(),
                       Vector2{
                           .x = (float) (currentButton.width - buttonTextSize.x) / 2 + currentButton.xPos + 0.5f,
                           .y = (float) (currentButton.height - buttonTextSize.y) / 2 + currentButton.yPos
                       },
                       buttonFontSize, 0.f, currentButton.textColor);
        }
    }
}

void EngineApplication::renderLines(int zIdx) {
    for (const UI::Line &currentLine: lines_pipeline) {
        if (currentLine.zIndex != zIdx) continue;
        DrawLineEx(Vector2{.x = static_cast<float>(currentLine.xStartPos), .y = static_cast<float>(currentLine.yStartPos)},
                   Vector2{.x = static_cast<float>(currentLine.xEndPos), .y = static_cast<float>(currentLine.yEndPos)},
                   static_cast<float>(currentLine.thickness),
                   currentLine.color
        );
    }
}
