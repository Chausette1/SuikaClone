#include "orange.h"

orange::orange() : fruit() {
    radius = 30;
    sprite = LoadTexture("resources/img/circle3.png");
}

orange::~orange() {
    UnloadTexture(sprite);
}

fruit* orange::Fusion(fruit* otherFruit) {
    orange* other = dynamic_cast<orange*>(otherFruit);
    

    int newX = (x + other->x) / 2;
    int newY = (y + other->y) / 2;
    fruit* newFruit = new pomme();
    newFruit->x = newX;
    newFruit->y = newY;
    return newFruit;
}