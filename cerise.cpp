#pragma once
#include "include.h"

cerise::cerise() : fruit()
{
	size = 20;
	sprite = LoadTexture("resources/img/circle0.png");
}

void cerise::draw()
{
	int SpriteSize = size;
	Rectangle sourceRec = { 0.0f, 0.0f, (float)sprite.width, (float)sprite.height };
	Rectangle destRec = { (float)x, (float)y, SpriteSize,SpriteSize };
	Vector2 origin = { (float)size / 2, (float)size / 2 };
	DrawTexturePro(sprite, sourceRec, destRec, origin, 0.0f, WHITE);
}