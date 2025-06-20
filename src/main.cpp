#include <raylib.h>
#include <iostream>

int main()
{
    InitWindow(800, 600, "make the game!");
    // That's basically setting target refresh rate as monitor does
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        EndDrawing();

        std::cout << GetFPS() << std::endl;
    }

    CloseWindow();
}