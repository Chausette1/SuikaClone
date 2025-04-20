#pragma once

#include "pamplemousse.h"
#include "game.h"

pamplemousse::pamplemousse() : fruit() {
	radius = 95;
	sprite = game::sprite7;
	type = "pamplemousse";
}

pamplemousse::~pamplemousse() {
	fruit::~fruit();
}

std::shared_ptr<fruit> pamplemousse::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 60;
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<ananas>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}
