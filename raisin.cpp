#pragma once

#include "raisin.h"

raisin::raisin() : fruit()
{
	radius = 30;
	sprite = LoadTexture("resources/img/circle2.png");
}
raisin::~raisin()
{
	fruit::~fruit();
	UnloadTexture(sprite);
}
fruit* raisin::Fusion(fruit* otherFruit) {
    raisin* other = dynamic_cast<raisin*>(otherFruit);

    int newX = (x + other->x) / 2;
    int newY = (y + other->y) / 2;
    fruit* newFruit = new mandarine();
    newFruit->x = newX;
    newFruit->y = newY;
    return newFruit;
}

