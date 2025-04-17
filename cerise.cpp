#pragma once
#include "cerise.h"
#include "game.h"

cerise::cerise() : fruit()
{
	radius = 15;
	sprite = game::sprite0;
}
cerise::~cerise() {
	fruit::~fruit();
}
fruit* cerise::Fusion(fruit* otherFruit) {
	cerise* other = dynamic_cast<cerise*>(otherFruit);


	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	fruit* newFruit = new fraise();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}

