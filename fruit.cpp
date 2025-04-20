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
	type = "fruit";
	radius = 0;
	sprite = {};
}

fruit::~fruit()
{
	currentCollision = nullptr;
}

void fruit::ManageFruitOverlap(std::shared_ptr<fruit> fixedFruitCollision) {
	bool asTopCollision = false;
	for (std::shared_ptr<fruit> f : listCollision)
	{
		if (f == fixedFruitCollision)
			continue;
		if (y > f->y)
		{
			asTopCollision = true;
		}
	}
	if (asTopCollision) {
		for (std::shared_ptr<fruit> f : listCollision)
		{
			if (f == fixedFruitCollision)
				continue;
			if (y > f->y)
				f->ManageCollision(shared_from_this());
		}
	}
	while (IsColliding(fixedFruitCollision))
	{
		y--;
	}
	y--;
}

bool fruit::ManageFruitXCollision() {
	if (currentCollision == nullptr)
	{
		return false;
	}
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
	if (CheckCollisionCircleRec(Vector2{ static_cast<float>(x), static_cast<float>(y) }, static_cast<float>(radius), leftEdge)) {
		x++;
		EndFall();
		return;
	}
	else if (CheckCollisionCircleRec(Vector2{ static_cast<float>(x), static_cast<float>(y) }, static_cast<float>(radius), RightEdge)) {
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
	for (auto f : listCollision)
	{
		f = nullptr;
	}
	return;
}

bool fruit::ManageCollision(std::shared_ptr<fruit> newCollision) {
	bool newCollisionInList = false;
	for (std::shared_ptr<fruit> oldCollision : listCollision)
	{
		if (oldCollision == newCollision)
		{
			newCollisionInList = true;
			break;
		}
	}
	if (!newCollisionInList)
	{
		currentCollision = newCollision;
		listCollision.push_back(newCollision);
	}
	else
	{
		if (currentCollision == newCollision)
		{
			return false;
		}
		else {
			EndFall();
			return true;
		}
	}
	return false;
}

void fruit::DoCollision(std::vector<std::shared_ptr<fruit>>& listFruits, std::shared_ptr<fruit> collision) {
	{
		if (ManageCollision(collision))
		{
			return;
		}
		if (collision) {
			ManageFruitOverlap(collision);
			if (ManageFruitXCollision())
			{
				return;
			}
			CheckIfHitBoxesAreHit();
		}
	}
}

void fruit::fall(std::vector<std::shared_ptr<fruit>>& listFruits, int& score)
{
	//make hitbox
	y += 1;
	CheckIfHitBoxesAreHit();
	for (std::shared_ptr<fruit> f : listFruits) {
		if (IsColliding(f))
		{
			bool IsFusion = DoFusion(f, listFruits, score);
			if (IsFusion)
			{
				return;
			}
			DoCollision(listFruits, f);
		}
	}
}

bool fruit::DoFusion(std::shared_ptr<fruit> f, std::vector<std::shared_ptr<fruit>>& listFruits, int& score)
{
	if (IsFusion(f))
	{
		std::shared_ptr<fruit> newFruit = Fusion(f, score);
		shared_from_this()->aEffacer = true;
		f->aEffacer = true;
		if (newFruit)
		{
			listFruits.push_back(newFruit);
			newFruit->isFalling = true;
			return true;
		}
	}
	return false;
}


void fruit::draw()
{
	DrawCircle(x, y, static_cast<float>(radius), BLUE);
	Rectangle sourceRec = { 0.0f, 0.0f, static_cast<float>(sprite.width), static_cast<float>(sprite.height) };
	Rectangle destRec = { static_cast<float>(x), static_cast<float>(y), static_cast<float>(radius * 2), static_cast<float>(radius * 2) };
	Vector2 origin = { static_cast<float>(radius), static_cast<float>(radius) };
	DrawTexturePro(sprite, sourceRec, destRec, origin, static_cast<float>(angle), WHITE);
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

bool fruit::IsColliding(std::shared_ptr<fruit> otherFruit)
{
	Vector2 myPos = { static_cast<float>(x), static_cast<float>(y) };
	Vector2 otherPos = { static_cast<float>(otherFruit->x), static_cast<float>(otherFruit->y) };
	return CheckCollisionCircles(myPos, static_cast<float>(radius), otherPos, static_cast<float>(otherFruit->radius));
}

bool fruit::IsFusion(std::shared_ptr<fruit> otherFruit) {
	return typeid(*shared_from_this()) == typeid(*otherFruit);

}

std::shared_ptr<fruit> fruit::Fusion(std::shared_ptr<fruit> otherFruit, int& score)
{
	return std::shared_ptr<fruit>(nullptr);
}
