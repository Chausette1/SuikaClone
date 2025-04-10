#pragma once

#include "include.h"

class game
{
public:
	Texture2D background;
	Texture2D box;
	droppeur* mydroppeur;
	fruit* currentFruit;
	std::vector<fruit*> fruits;

	game(int width, int height);
	void update(bool IsMousePressed);
	void draw();
private:
	int numberOfFruits;
	int screenWidth;
	int screenHeight;
	int boxWidth;
	int boxHeight;
	void drawFruits();
	void drawDroppeur();
	void drawBackground();
	void drawBox();
	bool checkIfFruitIsFall();
	fruit* getRandomFruit(int f);
};

