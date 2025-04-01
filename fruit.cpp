#pragma once
#include "include.h"

fruit::fruit()
{
	x = GetMouseX();
	y = 160;
	speed = 10;
	isFalling = false;
	isFall = false;
}

void fruit::fall()
{
	if (!isFall)
	{
		isFalling = true;
	}
	if (isFalling)
	{
		y += speed;
		int minY = 850 - (size / 2) - 10;
		if (y > minY)
		{
			isFalling = false;
			isFall = true;
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

void fruit::setFall(bool fall)
{
	isFalling = fall;
}

bool fruit::getIsFall()
{
	return isFall;
}

void fruit::updateX()
{
	int MouseX = GetMouseX();
	int minX = 180;
	int maxX = 620;
	if (MouseX > minX && MouseX < maxX)
	{
		x = MouseX;
	}
	else if (MouseX <= minX)
	{
		x = minX;
	}
	else if ((MouseX >= maxX))
	{
		x = maxX;
	}
}