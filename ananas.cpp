#pragma once

#include "ananas.h"

ananas::ananas() : fruit()
{
	radius = 110;
	sprite = LoadTexture("resources/img/circle8.png");
}
ananas::~ananas()
{
	fruit::~fruit();
	UnloadTexture(sprite);
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