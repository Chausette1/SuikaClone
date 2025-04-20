#pragma once

#include "fraise.h"
#include "game.h"

fraise::fraise() : fruit() {
	radius = 20;
	sprite = game::sprite1;
}

fraise::~fraise() {
	fruit::~fruit();
}

std::shared_ptr<fruit> fraise::Fusion(std::shared_ptr<fruit> otherFruit) {
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<raisin>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}