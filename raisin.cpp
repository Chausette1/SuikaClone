#pragma once

#include "raisin.h"
#include "game.h"

raisin::raisin() : fruit()
{
	radius = 30;
	sprite = game::sprite2;
}
raisin::~raisin()
{
	fruit::~fruit();
}
fruit* raisin::Fusion(fruit* otherFruit) {
	raisin* other = dynamic_cast<raisin*>(otherFruit);

	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	std::cout << "on créee une madarine" << std::endl;
	fruit* newFruit = new mandarine();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}

