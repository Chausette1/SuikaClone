#pragma once
#include "include.h"
#include "game.h"

int main()
{
	InitWindow(800, 900, "SuikaClone");
	SetTargetFPS(600);

	game* mygame = new game(800, 900);
	bool IsMousePressed = false;

	while (!WindowShouldClose())
	{
		mygame->update();
		if (mygame->lose)
		{
			mygame = new game(800, 900);
		}
	}

	CloseWindow();
	return 0;
}
