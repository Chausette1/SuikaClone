#pragma once

#include "peach.h"
#include "game.h"

peach::peach() : fruit() {
	radius = 80;
	sprite = game::sprite6;
}

peach::~peach() {
	fruit::~fruit();
}

fruit* peach::Fusion(fruit* otherFruit) {
	peach* other = dynamic_cast<peach*>(otherFruit);

	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	fruit* newFruit = new pamplemousse();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}