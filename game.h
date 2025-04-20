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
#include "game_state_recorder.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class game
{
public:
	Texture2D background;
	Texture2D box;
	droppeur* mydroppeur;
	std::shared_ptr<fruit> currentFruit;
	std::vector<std::shared_ptr<fruit>> fruits;
	game(int width, int height);
	~game();
	void update();
	void draw();
	void DoFall(std::shared_ptr<fruit> fallenFruit);
	bool lose;
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
	int score;
	void drawFruits();
	void drawDroppeur();
	void drawBackground();
	void drawBox();
	bool checkIfFruitIsFall();
	std::shared_ptr<fruit> getRandomFruit(int f);
	void drawLose();
	std::mt19937 gen;
	std::uniform_int_distribution<> distrib;

	// Nouvelles fonctions pour l'enregistrement des états
	void recordGameState(float actionX);
	GameState getCurrentGameState() const;
	GameState getNextGameState() const;
	int calculateReward() const;
	bool isGameDone() const;
};
