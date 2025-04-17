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
fruit* watermelon::Fusion(fruit* otherFruit) {
	return nullptr;
}
