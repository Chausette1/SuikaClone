#pragma once

#include "include.h"

class fruit
{
private:
	int x;
	int y;
	int speed;
	int size;
	bool isFalling;
	Texture2D sprite;

public:
	fruit();
	void draw();
	void fall();
	bool getIsFalling();
	void updateX();
};