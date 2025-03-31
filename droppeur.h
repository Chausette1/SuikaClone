#pragma once
#include "include.h"

class droppeur
{
private:
	int x;
	const int y;
	Texture2D sprite;

public:
	droppeur();
	void updateX();
	void draw();
};
