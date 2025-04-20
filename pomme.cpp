#pragma once

#include "pomme.h"
#include "game.h"

pomme::pomme() : fruit() {
	radius = 40;
	sprite = game::sprite5;
	type = "pomme";
}

pomme::~pomme() {
	fruit::~fruit();
}

std::shared_ptr<fruit> pomme::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 35;
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<peach>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}