#pragma once

#include "peach.h"
#include "game.h"

peach::peach() : fruit() {
	radius = 80;
	sprite = game::sprite6;
	type = "peach";
}

peach::~peach() {
	fruit::~fruit();
}

std::shared_ptr<fruit> peach::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 50;
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<pamplemousse>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}