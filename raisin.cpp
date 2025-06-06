#pragma once

#include "raisin.h"
#include "game.h"

raisin::raisin() : fruit()
{
	radius = 30;
	sprite = game::sprite2;
	type = "raisin";
}
raisin::~raisin()
{
	fruit::~fruit();
}
std::shared_ptr<fruit> raisin::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 20;
	int newX = (x + otherFruit->x) / 2;
	int newY = (y + otherFruit->y) / 2;
	std::shared_ptr<fruit> newFruit = std::make_shared<mandarine>();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}

