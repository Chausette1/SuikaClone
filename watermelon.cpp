#pragma once

#include "watermelon.h"

watermelon::watermelon() : fruit()
{
	radius = 130;
	sprite = LoadTexture("resources/img/circle10.png");
}

watermelon::~watermelon()
{
	fruit::~fruit();
	UnloadTexture(sprite);
}
fruit* watermelon::Fusion(fruit* otherFruit) {
	return nullptr;
}
