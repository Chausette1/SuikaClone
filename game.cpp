#pragma once

#include "include.h"

game::game(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
	boxWidth = 600;
	boxHeight = 800;
	background = LoadTexture("resources/img/background.png");
	box = LoadTexture("resources/img/box2.png");
	mydroppeur = new droppeur();
	currentFruit = getRandomFruit();
	fruits = std::vector<fruit*>();
}

void game::drawBackground()
{
	Rectangle sourceRec = { 0.0f, 0.0f, static_cast<float>(background.width), static_cast<float>(background.height) };
	Rectangle destRec = { 0.0f, 0.0f, static_cast<float>(screenWidth), static_cast<float>(screenHeight) };
	Vector2 origin = { 0,0 };
	DrawTexturePro(background, sourceRec, destRec, origin, 0.0f, WHITE);
}

bool game::checkIfFruitIsFall()
{
	bool result = false;
	for (fruit* f : fruits)
	{
		if (f->getIsFalling())
		{
			result = true;
			break;
		}
	}
	return result;
}

void game::drawFruits()
{
	for (fruit* f : fruits)
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
	EndDrawing();
}

void game::update(bool IsMousePressed)
{
	mydroppeur->updateX();

	if (!currentFruit->getIsFalling() && !currentFruit->getIsFall())
	{
		currentFruit->updateX();
		if (IsMousePressed)
		{
			currentFruit->setFall(true);
			currentFruit->fall(fruits);
		}
	}
	if (currentFruit->getIsFalling())
	{
		currentFruit->fall(fruits);
	}
	else if (currentFruit->getIsFall())
	{
		fruits.push_back(currentFruit);
		currentFruit = getRandomFruit();
	}

	draw();
}

fruit* game::getRandomFruit() {
	int random = (rand() % 100) + 1;
	if (random < 40) {
		return new cerise();
	}
	else if (random < 75) {
		return new fraise();
	}
	else if (random < 90) {
		return new raisin();
	}
	else if (random < 95) {
		return new mandarine();
	}
	else {
		return new orange();
	}
}