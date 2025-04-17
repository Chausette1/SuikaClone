#pragma once

#include "orange.h"
#include "game.h"

orange::orange() : fruit() {
	radius = 50;
	sprite = game::sprite4;
}

orange::~orange() {
	fruit::~fruit();
}

fruit* orange::Fusion(fruit* otherFruit) {
	orange* other = dynamic_cast<orange*>(otherFruit);


	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	fruit* newFruit = new pomme();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}