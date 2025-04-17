#pragma once
#include "include.h"
#include "game.h"

int main()
{
	InitWindow(800, 900, "Hello World");
	SetTargetFPS(1000);

	game* mygame = new game(800, 900);
	bool IsMousePressed = false;

	while (!WindowShouldClose())
	{
		mygame->update();
		mygame->draw();
	}

	CloseWindow();
	return 0;
}
