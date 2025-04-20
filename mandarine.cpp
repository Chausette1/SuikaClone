#pragma once

#include "mandarine.h"
#include "game.h"

mandarine::mandarine() : fruit() {
	radius = 30;
	sprite = game::sprite3;
	type = "mandarine";
}

mandarine::~mandarine() {
	fruit::~fruit();
}

std::shared_ptr<fruit> mandarine::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 25;
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<orange>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}