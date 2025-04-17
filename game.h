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
	void update();
	void draw();
	void DoFall(fruit* fallenFruit);
	static Texture2D sprite0;
	static Texture2D sprite1;
	static Texture2D sprite2;
	static Texture2D sprite3;
	static Texture2D sprite4;
	static Texture2D sprite5;
	static Texture2D sprite6;
	static Texture2D sprite7;
	static Texture2D sprite8;
	static Texture2D sprite9;
	static Texture2D sprite10;

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
