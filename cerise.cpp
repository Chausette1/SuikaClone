#pragma once
#include "cerise.h"
#include "game.h"

cerise::cerise() : fruit()
{
	radius = 15;
	sprite = game::sprite0;
	type = "cerise";
}
cerise::~cerise() {
	fruit::~fruit();
}
std::shared_ptr<fruit> cerise::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 10;
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<fraise>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}

