#include "include.h"

fruit::fruit()
{
	x = GetMouseX();
	y = 140;
	speed = 10;
}

void fruit::fall()
{
	if (isFalling)
	{
		y += speed;
		if (y > 850)
		{
			isFalling = false;
		}
	}
}

void fruit::draw()
{
	Rectangle sourceRec = { 0.0f, 0.0f, (float)sprite.width, (float)sprite.height };
	Rectangle destRec = { (float)x, (float)y, size, size };
	Vector2 origin = { (float)size / 2, (float)size / 2 };
	DrawTexturePro(sprite, sourceRec, destRec, origin, 0.0f, WHITE);
}

bool fruit::getIsFalling()
{
	return isFalling;
}

void fruit::updateX()
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