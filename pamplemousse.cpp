#include "pamplemousse.h"

pamplemousse::pamplemousse() : fruit() {
	radius = 95;
	sprite = LoadTexture("resources/img/circle6.png");
}

pamplemousse::~pamplemousse() {
	UnloadTexture(sprite);
}

fruit* pamplemousse::Fusion(fruit* otherFruit) {
	pamplemousse* other = dynamic_cast<pamplemousse*>(otherFruit);

	int newX = (x + other->x) / 2;
	int newY = (y + other->y) / 2;
	fruit* newFruit = new ananas();
	newFruit->x = newX;
	newFruit->y = newY;
	return newFruit;
}
