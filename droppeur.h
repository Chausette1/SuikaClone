#pragma once
#include "include.h"

class droppeur
{
private:
	int x;
	const int y;
	const int size;
	Texture2D sprite;

public:
	droppeur();
	~droppeur() { UnloadTexture(sprite); }
	void updateX();
	void draw() const;
};
