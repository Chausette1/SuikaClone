#include "mandarine.h"

mandarine::mandarine() : fruit() {
    radius = 25;
    sprite = LoadTexture("resources/img/circle2.png");
}

mandarine::~mandarine() {
    UnloadTexture(sprite);
}

fruit* mandarine::Fusion(fruit* otherFruit) {
    mandarine* other = dynamic_cast<mandarine*>(otherFruit);
    

    int newX = (x + other->x) / 2;
    int newY = (y + other->y) / 2;
    fruit* newFruit = new orange();
    newFruit->x = newX;
    newFruit->y = newY;
    return newFruit;
}