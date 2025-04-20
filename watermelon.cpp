#pragma once

#include "watermelon.h"
#include "game.h"

watermelon::watermelon() : fruit()
{
	radius = 130;
	sprite = game::sprite10;
}

watermelon::~watermelon()
{
	fruit::~fruit();
}
std::shared_ptr<fruit> watermelon::Fusion(std::shared_ptr<fruit> otherFruit, int& score) {
	score += 250;
	return nullptr;
}
