#pragma once
#include "fruit.h"

fruit::fruit()
{
	x = GetMouseX();
	y = 160;
	speed = 10;
	isFalling = false;
	isFall = false;
	angle = 0;
	Collision = false;
	currentCollision = nullptr;
	aEffacer = false;
}

fruit::~fruit()
{
	this->currentCollision = nullptr;
}

void fruit::ManageFruitOverlap() {
	if (currentCollision == nullptr)
	{
		return;
	}
	if (y < currentCollision->y) {

		while (IsColliding(currentCollision))
		{
			y--;
		}
		y--;
	}
	else {
		currentCollision->ManageFruitOverlap();
	}
}

bool fruit::ManageFruitXCollision() {
	if (x == currentCollision->x) {
		EndFall();
		return true;
	}
	else if (x > currentCollision->x) {
		x++;
		x++;
		angle += 5;
	}
	else {
		x--;
		x--;
		angle -= 5;
	}
	return false;
}

void fruit::CheckIfHitBoxesAreHit() {
	if (y + radius >= 830)
	{
		y = 830 - radius;
		EndFall();
		return;
	}
	if (CheckCollisionCircleRec(Vector2{ (float)x, (float)y }, radius, leftEdge)) {
		x++;
		EndFall();
		return;
	}
	else if (CheckCollisionCircleRec(Vector2{ (float)x, (float)y }, radius, RightEdge)) {
		x--;
		EndFall();
		return;
	}
}

void fruit::EndFall()
{
	isFall = true;
	isFalling = false;
	currentCollision = nullptr;
	for (fruit* f : listCollision)
	{
		listCollision.erase(std::remove(listCollision.begin(), listCollision.end(), f), listCollision.end());
	}
	return;
}

bool fruit::ManageCollision(fruit* newCollision) {
	bool newCollisionInList = false;
	for (fruit* oldCollision : listCollision)
	{
		if (oldCollision == newCollision)
		{
			newCollisionInList = true;
			break;
		}
	}
	if (!newCollisionInList)
	{
		std::cout << newCollision << std::endl;
		currentCollision = newCollision;
		std::cout << currentCollision << std::endl;
		std::cout << "list colision : " << listCollision.size() << std::endl;
		listCollision.push_back(newCollision);
	}
	else
	{
		std::cout << "déjà dans la liste" << std::endl;
		if (currentCollision == newCollision)
		{
			std::cout << currentCollision << std::endl;
			return false;
		}
		else {
			EndFall();
			return true;
		}
	}
	return false;
}

void fruit::DoCollision(std::vector<fruit*> listFruits, fruit* f) {
	{
		if (ManageCollision(f))
		{
			return;
		}
		ManageFruitOverlap();
		if (ManageFruitXCollision())
		{
			return;
		}
		CheckIfHitBoxesAreHit();
	}
}

void fruit::fall(std::vector<fruit*>& listFruits)
{
	//make hitbox
	y += 1;
	CheckIfHitBoxesAreHit();
	for (fruit* f : listFruits) {
		if (f == this)
		{
			continue;
		}
		if (IsColliding(f))
		{
			bool IsFusion = DoFusion(f, listFruits);
			if (IsFusion)
			{
				return;
			}
			DoCollision(listFruits, f);
		}
	}
}

bool fruit::DoFusion(fruit* f, std::vector<fruit*>& listFruits)
{
	if (IsFusion(f))
	{
		fruit* newFruit = Fusion(f);
		newFruit->isFalling = true;
		this->aEffacer = true;
		f->aEffacer = true;
		listFruits.push_back(newFruit);
		listCollision.erase(std::remove(listCollision.begin(), listCollision.end(), f), listCollision.end());
		return true;
	}
	return false;
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

void fruit::setFalling(bool fall)
{
	isFalling = fall;
}

void fruit::setFall(bool fall)
{
	isFall = fall;
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

bool fruit::IsFusion(fruit* otherFruit) {
	return typeid(*this) == typeid(*otherFruit);

}
