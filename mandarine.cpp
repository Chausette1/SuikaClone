#pragma once

#include "mandarine.h"
#include "game.h"

mandarine::mandarine() : fruit() {
	radius = 40;
	sprite = game::sprite3;
}

mandarine::~mandarine() {
	fruit::~fruit();
}

fruit* mandarine::Fusion(fruit* otherFruit) {
	mandarine* other = dynamic_cast<mandarine*>(otherFruit);


	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	fruit* newFruit = new orange();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}