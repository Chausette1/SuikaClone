#pragma once

#include "include.h"

class fruit
{
protected:
	int x;
	int y;
	int speed;
	int size;
	bool isFalling;
	Texture2D sprite;
	fruit();

public:
	void virtual draw();
	void virtual fall();
	bool virtual getIsFalling();
	void virtual updateX();
};