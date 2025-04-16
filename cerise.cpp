#pragma once
#include "cerise.h"

cerise::cerise() : fruit()
{
	radius = 15;
	sprite = LoadTexture("resources/img/circle0.png");
}
cerise::~cerise(){
	fruit::~fruit();
	UnloadTexture(sprite);
}
fruit* cerise::Fusion(fruit* otherFruit) {
    cerise* other = dynamic_cast<cerise*>(otherFruit);
    

    int newX = (x + other->x) / 2;
    int newY = (y + other->y) / 2;
    fruit* newFruit = new fraise();
    newFruit->x = newX;
    newFruit->y = newY;
	return newFruit;
}

