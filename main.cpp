#include "include.h"

void DrawContainer(droppeur drop, fruit& fruit) {
	drop.updateX();
	fruit.updateX();
	Color color = { 255, 244, 157, 255 };
	DrawRectangle(180, 210, 10, 650, color);
	DrawRectangle(620, 210, 10, 650, color);
	DrawRectangle(180, 850, 440, 10, color);
	drop.draw();
	fruit.draw();
}

int main()
{
	InitWindow(800, 900, "Hello World");
	SetTargetFPS(60);
	droppeur droppeur;
	while (!WindowShouldClose()) {
		BeginDrawing();
		Color backColor = { 194, 162, 79, 255 };
		ClearBackground(backColor);

		DrawContainer(droppeur, );
		DrawText("Hello World", 10, 10, 20, LIGHTGRAY);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
