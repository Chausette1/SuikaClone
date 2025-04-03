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
	bool isFall;
	Texture2D sprite;
	fruit();

public:
	void virtual draw();
	void virtual fall(std::vector<fruit*> listFruits);
	bool virtual getIsFalling();
	void virtual setFall(bool fall);
	bool virtual getIsFall();
	void virtual updateX();
	bool virtual IsColliding(fruit* otherFruit);
};