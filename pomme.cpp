#include "pomme.h"

pomme::pomme() : fruit() {
    radius = 50;
    sprite = LoadTexture("resources/img/circle7.png");
}

pomme::~pomme() {
    UnloadTexture(sprite);
}

fruit* pomme::Fusion(fruit* otherFruit) {
    pomme* other = dynamic_cast<pomme*>(otherFruit);

    int newX = (x + other->x) / 2;
    int newY = (y + other->y) / 2;
    fruit* newFruit = new peach();
    newFruit->x = newX;
    newFruit->y = newY;
    return newFruit;
}