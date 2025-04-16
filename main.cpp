#pragma once
#include "include.h"
#include "game.h"

int main()
{
    InitWindow(800, 900, "Hello World");
    SetTargetFPS(144);

    game* mygame = new game(800, 900);
    bool IsMousePressed = false;

    while (!WindowShouldClose())
    {
       
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            IsMousePressed = true;
        }

        
        mygame->update(IsMousePressed);

        
        IsMousePressed = false;

       
        mygame->draw();
    }

    CloseWindow();
    return 0;
}
