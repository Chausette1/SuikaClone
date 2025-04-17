#pragma once

#include "pomme.h"
#include "game.h"

pomme::pomme() : fruit() {
	radius = 65;
	sprite = game::sprite5;
}

pomme::~pomme() {
	fruit::~fruit();
}

fruit* pomme::Fusion(fruit* otherFruit) {
	pomme* other = dynamic_cast<pomme*>(otherFruit);

	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	fruit* newFruit = new peach();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}