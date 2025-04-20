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
	Vector2 origin = { 0,0 };
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
	Rectangle sourceRec = { 0.0f, 0.0f, box.width, box.height };
	Rectangle destRec = { 100.0f, 100.0f, boxWidth, boxHeight };
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
		/*while (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			mydroppeur->updateX();
			currentFruit->updateX();
			draw();
		}*/
		int mouseX = 180 + (distrib(gen) * 4) + (distrib(gen) / 10 * 4);
		currentFruit->x = mouseX;

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
		draw();
	}
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
	DrawText("PERDU.", screenWidth / 2 - 30, screenHeight / 2 - 30, 60, BLACK);
	EndDrawing();
}
