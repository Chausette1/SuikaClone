#pragma once

#include "melon.h"

melon::melon() : fruit() {
	radius = 120;
	sprite = game::sprite9;
	type = "melon";
}

melon::~melon() {
	fruit::~fruit();
}

std::shared_ptr<fruit> melon::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 70;
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<watermelon>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}
