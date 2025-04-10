#pragma once
#include "include.h"

fruit::fruit()
{
	x = GetMouseX();
	y = 160;
	speed = 10;
	isFalling = false;
	isFall = false;
	angle = 0;
	bool Collision = false;
	fruit* currentCollision = nullptr;
}

void fruit::ManageFruitOverlap() {
	while (IsColliding(currentCollision))
	{
		y--;
	}
	y++;
}

void fruit::ManageFruitXCollision() {
	if (x == currentCollision->x) {
		isFall = true;
		isFalling = false;
		return;
	}
	else if (x > currentCollision->x) {
		x++;
		angle += 5;
	}
	else {
		x--;
		angle -= 5;
	}
}

void fruit::CheckIfHitBoxesAreHit() {
	if (CheckCollisionCircleRec(Vector2{ (float)x, (float)y }, radius, leftEdge) ||
		CheckCollisionCircleRec(Vector2{ (float)x, (float)y }, radius, RightEdge) ||
		CheckCollisionCircleRec(Vector2{ (float)x, (float)y }, radius, BottomEdge))
	{
		isFall = true;
		isFalling = false;
		return;
	}
}

void fruit::ManageMultipleCollision(fruit* newCollision, std::vector<fruit*> listFruits) {
	Collision = true;
	currentCollision = newCollision;
	for (fruit* oldCollision : listFruits)
	{
		if (newCollision == oldCollision)
		{
			isFall = true;
			isFalling = false;
			return;
		}
		else
		{
			Collision = true;
			currentCollision = newCollision;
			listCollision.push_back(newCollision);
		}
	}
}

void fruit::DoCollision(std::vector<fruit*> listFruits) {
	{
		ManageFruitOverlap();
		ManageFruitXCollision();
		CheckIfHitBoxesAreHit();
		Collision = false;
		for (fruit* newCollision : listFruits)
		{
			if (newCollision == currentCollision)
			{
				continue;
			}
			if (IsColliding(newCollision))
			{
				ManageMultipleCollision(newCollision, listFruits);
			}
		}
	}
}

void fruit::fall(std::vector<fruit*> listFruits)
{
	//make hitbox

	isFalling = true;
	draw();
	y += speed;
	CheckIfHitBoxesAreHit();
	if (!Collision) {
		for (fruit* f : listFruits) {
			if (IsColliding(f))
			{
				Collision = true;
				currentCollision = f;
				listCollision.push_back(f);
			}
		}
	}
	if (Collision) {
		DoCollision(listFruits);
	}
}


void fruit::draw()
{
	DrawCircle(x, y, radius, BLUE);
	Rectangle sourceRec = { 0.0f, 0.0f, (float)sprite.width, (float)sprite.height };
	Rectangle destRec = { (float)(x), (float)(y), radius * 2, radius * 2 };
	Vector2 origin = { radius,radius };
	DrawTexturePro(sprite, sourceRec, destRec, origin, float(angle), WHITE);
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
	return CheckCollisionCircles(myPos, (float)radius, otherPos, (float)otherFruit->radius);
}