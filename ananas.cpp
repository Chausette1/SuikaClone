#pragma once

#include "ananas.h"
#include "game.h"

ananas::ananas() : fruit()
{
	radius = 110;
	sprite = game::sprite8;
	type = "ananas";
}
ananas::~ananas()
{
	fruit::~fruit();
}
std::shared_ptr<fruit> ananas::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 70;
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<melon>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}