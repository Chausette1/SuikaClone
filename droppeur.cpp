#include "include.h"

droppeur::droppeur() : y(120), size(200)
{
	x = 400;
	sprite = LoadTexture("resources/img/droppeur.png");
}

void droppeur::updateX()
{
	int MouseX = GetMouseX();
	if (MouseX > 190 && MouseX < 620)
	{
		x = MouseX;
	}
	else if (MouseX <= 190)
	{
		x = 190;
	}
	else if (MouseX >= 620)
	{
		x = 620;
	}
}

void droppeur::draw()
{
	Rectangle sourceRec = { 0.0f, 0.0f, (float)sprite.width, (float)sprite.height };
	Rectangle destRec = { (float)x, (float)y, size, size };
	Vector2 origin = { (float)size / 2, (float)size / 2 };
	DrawTexturePro(sprite, sourceRec, destRec, origin, 0.0f, WHITE);
}