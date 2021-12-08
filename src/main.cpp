#include "raylib.h"
#include <iostream>

int main()
{
    InitWindow(600, 600, "Катя, зноу палучилося, еще сильнее!");
    while(!WindowShouldClose())
    { 
        BeginDrawing();
            ClearBackground(SKYBLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
