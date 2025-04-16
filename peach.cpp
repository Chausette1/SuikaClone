#include "peach.h"

peach::peach() : fruit() {
    radius = 45;
    sprite = LoadTexture("resources/img/circle6.png");
}

peach::~peach() {
    UnloadTexture(sprite);
}

fruit* peach::Fusion(fruit* otherFruit) {
    peach* other = dynamic_cast<peach*>(otherFruit);

    int newX = (x + other->x) / 2;
    int newY = (y + other->y) / 2;
    fruit* newFruit = new pamplemousse();
    newFruit->x = newX;
    newFruit->y = newY;
    return newFruit;
}