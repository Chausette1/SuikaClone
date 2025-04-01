#pragma once
#include "include.h"

droppeur::droppeur() : y(120), size(200)
{
	x = 400;
	sprite = LoadTexture("resources/img/droppeur.png");
}

void droppeur::updateX()
{
	int minX = 180;
	int maxX = 620;
	int MouseX = GetMouseX();
	if (MouseX > minX && MouseX < maxX)
	{
		x = MouseX;
	}
	else if (MouseX <= minX)
	{
		x = minX;
	}
	else if (MouseX >= maxX)
	{
		x = maxX;
	}
}

void droppeur::draw() const
{
	Rectangle sourceRec = { 0.0f, 0.0f, (float)sprite.width, (float)sprite.height };
	Rectangle destRec = { (float)x, (float)y, size, size };
	Vector2 origin = { (float)size / 2, (float)size / 2 };
	DrawTexturePro(sprite, sourceRec, destRec, origin, 0.0f, WHITE);
}