#include "include.h"

fruit::fruit()
{
	x = GetRandomValue(190, 620);
	y = 140;
	speed = 10;
	size = 20;
	sprite = LoadTexture("resources/img/circle0.png");
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

bool fruit::getIsFalling()
{
	return isFalling;
}

void fruit::draw()
{
	int SpriteSize = 20;
	Rectangle sourceRec = { 0.0f, 0.0f, (float)sprite.width, (float)sprite.height };
	Rectangle destRec = { (float)x, (float)y, SpriteSize, SpriteSize };
	Vector2 origin = { (float)sprite.width / 2, (float)sprite.height / 2 };
	DrawTexturePro(sprite, sourceRec, destRec, origin, 0.0f, WHITE);
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