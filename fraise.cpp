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

fruit* fraise::Fusion(fruit* otherFruit) {
	fraise* other = dynamic_cast<fraise*>(otherFruit);


	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	std::cout << "on créee un raisin" << std::endl;
	fruit* newFruit = new raisin();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}