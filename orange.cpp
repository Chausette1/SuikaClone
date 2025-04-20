#pragma once

#include "orange.h"
#include "game.h"

orange::orange() : fruit() {
	radius = 50;
	sprite = game::sprite4;
	type = "orange";
}

orange::~orange() {
	fruit::~fruit();
}

std::shared_ptr<fruit> orange::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 30;
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<pomme>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}