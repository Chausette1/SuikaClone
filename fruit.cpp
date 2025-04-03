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

void fruit::fall(std::vector<fruit*> listFruits)
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
		for (fruit* f : listFruits)
		{
			if (IsColliding(f))
			{
				isFalling = false;
				isFall = true;
				y = f->y - size;
			}
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

bool fruit::IsColliding(fruit* otherFruit)
{
	Vector2 myPos = { (float)x, (float)y };
	Vector2 otherPos = { (float)otherFruit->x, (float)otherFruit->y };
	return CheckCollisionCircles(myPos, (float)size, otherPos, (float)otherFruit->size);
}