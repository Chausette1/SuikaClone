#pragma once

#include "include.h"
#include "droppeur.h"
#include "fruit.h"
#include "cerise.h"
#include "fraise.h"
#include "raisin.h"
#include "mandarine.h"
#include "orange.h"
#include "pomme.h"
#include "pamplemousse.h"
#include "peach.h"
#include "ananas.h"
#include "melon.h"
#include "watermelon.h"

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

