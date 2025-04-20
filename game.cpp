#pragma once

#include "game.h"
// Définition des variables statiques de sprites
Texture2D game::sprite0;
Texture2D game::sprite1;
Texture2D game::sprite2;
Texture2D game::sprite3;
Texture2D game::sprite4;
Texture2D game::sprite5;
Texture2D game::sprite6;
Texture2D game::sprite7;
Texture2D game::sprite8;
Texture2D game::sprite9;
Texture2D game::sprite10;

game::game(int width, int height) : gen(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count())),
distrib(1, 100)
{
	score = 0;
	numberOfFruits = 0;
	screenWidth = width;
	screenHeight = height;
	boxWidth = 600;
	boxHeight = 800;
	background = LoadTexture("resources/img/background.png");
	box = LoadTexture("resources/img/box2.png");
	mydroppeur = new droppeur();
	fruits = std::vector<std::shared_ptr<fruit>>();
	lose = false;

	sprite0 = LoadTexture("resources/img/circle0.png");
	sprite1 = LoadTexture("resources/img/circle1.png");
	sprite2 = LoadTexture("resources/img/circle2.png");
	sprite3 = LoadTexture("resources/img/circle3.png");
	sprite4 = LoadTexture("resources/img/circle4.png");
	sprite5 = LoadTexture("resources/img/circle5.png");
	sprite6 = LoadTexture("resources/img/circle7.png");
	sprite7 = LoadTexture("resources/img/circle6.png");
	sprite8 = LoadTexture("resources/img/circle8.png");
	sprite9 = LoadTexture("resources/img/circle9.png");
	sprite10 = LoadTexture("resources/img/circle10.png");
	currentFruit = getRandomFruit(numberOfFruits);
}

game::~game()
{
	for (std::shared_ptr<fruit> f : fruits)
	{
		f.reset();
	}
	fruits.clear();
	delete mydroppeur;
	mydroppeur = nullptr;
	UnloadTexture(background);
	UnloadTexture(box);
	UnloadTexture(sprite0);
	UnloadTexture(sprite1);
	UnloadTexture(sprite2);
	UnloadTexture(sprite3);
	UnloadTexture(sprite4);
	UnloadTexture(sprite5);
	UnloadTexture(sprite6);
	UnloadTexture(sprite7);
	UnloadTexture(sprite8);
	UnloadTexture(sprite9);
	UnloadTexture(sprite10);
}


bool game::checkIfFruitIsFall()
{
	bool result = false;
	for (std::shared_ptr<fruit> f : fruits)
	{
		if (f->getIsFalling())
		{
			result = true;
			break;
		}
	}
	return result;
}

void game::drawBackground()
{
	Rectangle sourceRec = { 0.0f, 0.0f, static_cast<float>(background.width), static_cast<float>(background.height) };
	Rectangle destRec = { 0.0f, 0.0f, static_cast<float>(screenWidth), static_cast<float>(screenHeight) };
	Vector2 origin = { 0.0f, 0.0f };
	DrawTexturePro(background, sourceRec, destRec, origin, 0.0f, WHITE);
}

void game::drawFruits()
{
	for (std::shared_ptr<fruit> f : fruits)
	{
		f->draw();
	}
	currentFruit->draw();
}

void game::drawDroppeur()
{
	mydroppeur->draw();
}

void game::drawBox()
{
	Rectangle sourceRec = { 0.0f, 0.0f, static_cast<float>(box.width), static_cast<float>(box.height) };
	Rectangle destRec = { 100.0f, 100.0f, static_cast<float>(boxWidth), static_cast<float>(boxHeight) };
	Vector2 origin = { 0.0f, 0.0f };
	DrawTexturePro(box, sourceRec, destRec, origin, 0.0f, WHITE);
}

void game::draw()
{
	BeginDrawing();
	ClearBackground(WHITE);
	drawBackground();
	drawBox();
	drawDroppeur();
	drawFruits();
	DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 20, BLACK);
	DrawText(TextFormat("Fruits: %i", fruits.size()), 10, 30, 20, BLACK);
	DrawText(TextFormat("Score: %i", score), 10, 50, 20, BLACK);
	EndDrawing();
}

void game::update()
{
	if (!lose)
	{
		float mouseX = static_cast<float>(180 + (distrib(gen) * 4) + (distrib(gen) / 10 * 4));
		currentFruit->x = static_cast<int>(mouseX);

		// Enregistrer l'état avant l'action
		recordGameState(mouseX);

		currentFruit->setFalling(true);
		DoFall(currentFruit);

		if (currentFruit->y < 280) {
			lose = true;
		}

		if (currentFruit->getIsFall())
		{
			fruits.push_back(currentFruit);
			currentFruit = getRandomFruit(numberOfFruits);
			numberOfFruits++;
		}
	}
	else {
		drawLose();
	}
}

void game::DoFall(std::shared_ptr<fruit> fallenFruit) {
	std::vector<std::shared_ptr<fruit>> toDelete;
	while (!fallenFruit->getIsFall() && fallenFruit->getIsFalling()) {
		fallenFruit->fall(fruits, score);
		if (fallenFruit->aEffacer) {
			numberOfFruits--;

			toDelete.push_back(fallenFruit);
			for (std::shared_ptr<fruit> f : fruits) {
				if (f->aEffacer) {
					toDelete.push_back(f);
					numberOfFruits--;
				}
			}

			// On nettoie
			for (std::shared_ptr<fruit> f : toDelete) {
				fruits.erase(std::remove(fruits.begin(), fruits.end(), f), fruits.end());
			}
			toDelete.clear();
			if (!fruits.empty()) {
				fallenFruit = fruits.back();
				currentFruit = fallenFruit;
				fruits.pop_back();
			}
		}
		mydroppeur->updateX();
	}
	draw();
}


std::shared_ptr<fruit> game::getRandomFruit(int f) {
	int random = distrib(gen);
	if (random < 40) {
		return std::make_shared<cerise>();
	}
	else if (random < 75) {
		return std::make_shared<fraise>();
	}
	else if (random < 90) {
		return std::make_shared<raisin>();
	}
	else if (random < 95) {
		return std::make_shared<mandarine>();
	}
	else {
		return std::make_shared<orange>();
	}
}

void game::drawLose()
{
	BeginDrawing();
	DrawText("PERDU.", static_cast<int>(screenWidth / 2 - 30), static_cast<int>(screenHeight / 2 - 30), 60, BLACK);
	EndDrawing();
}

void game::recordGameState(float actionX) {
	GameRecord record;
	
	// Game area
	record.game_area.x_min = 0;
	record.game_area.x_max = screenWidth;
	record.game_area.y_min = 0;
	record.game_area.y_max = screenHeight;
	
	// Current state
	record.state = getCurrentGameState();
	
	// Action
	record.action.x = actionX;
	
	// Next state
	record.next_state = getNextGameState();
	
	// Reward
	record.reward = calculateReward();
	
	// Done
	record.done = isGameDone();
	
	// Enregistrer l'état
	auto& recorder = GameStateRecorder::getInstance();
	recorder.recordGameState(record);
	recorder.saveToFile("game_records.json");
}

GameState game::getCurrentGameState() const {
	GameState state;
	
	// Liste des fruits actuels
	for (const auto& fruit : fruits) {
		FruitInfo fruitInfo;
		fruitInfo.type = fruit->getType();
		fruitInfo.x = static_cast<float>(fruit->x);
		fruitInfo.y = static_cast<float>(fruit->y);
		fruitInfo.radius = fruit->getRadius();
		state.list_fruit.push_back(fruitInfo);
	}
	
	// Fruit actuel
	if (currentFruit) {
		state.current_fruit.type = currentFruit->getType();
		state.current_fruit.x = static_cast<float>(currentFruit->x);
		state.current_fruit.y = static_cast<float>(currentFruit->y);
		state.current_fruit.radius = currentFruit->getRadius();
	}
	
	// Prochain fruit
	state.next_fruit = state.current_fruit;
	
	return state;
}

GameState game::getNextGameState() const {
	GameState state;
	
	// Copier l'état actuel
	state = getCurrentGameState();
	
	// Ajouter le fruit actuel à la liste des fruits
	if (currentFruit) {
		FruitInfo fruitInfo;
		fruitInfo.type = currentFruit->getType();
		fruitInfo.x = static_cast<float>(currentFruit->x);
		fruitInfo.y = static_cast<float>(currentFruit->y);
		fruitInfo.radius = currentFruit->getRadius();
		state.list_fruit.push_back(fruitInfo);
	}
	
	// Mettre à jour le fruit actuel avec le prochain fruit
	if (currentFruit) {
		state.current_fruit = state.next_fruit;
	}
	
	return state;
}

int game::calculateReward() const {
	// Logique de récompense à implémenter
	// Par exemple:
	// - Points pour les fusions
	// - Pénalité pour game over
	// - Bonus pour les combos
	return score;
}

bool game::isGameDone() const {
	return lose;
}
