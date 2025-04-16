#include "melon.h"

melon::melon() : fruit() {
	radius = 110;
	sprite = LoadTexture("resources/img/circle9.png");
}

melon::~melon() {
	UnloadTexture(sprite);
}

fruit* melon::Fusion(fruit* otherFruit) {
	melon* other = dynamic_cast<melon*>(otherFruit);


	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	fruit* newFruit = new watermelon();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}
