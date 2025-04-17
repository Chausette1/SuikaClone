#pragma once

#include "ananas.h"
#include "game.h"

ananas::ananas() : fruit()
{
	radius = 110;
	sprite = game::sprite8;
}
ananas::~ananas()
{
	fruit::~fruit();
}
fruit* ananas::Fusion(fruit* otherFruit) {
	ananas* other = dynamic_cast<ananas*>(otherFruit);


	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	fruit* newFruit = new melon();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}