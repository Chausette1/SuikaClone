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

game::game(int width, int height)
{
	numberOfFruits = 0;
	screenWidth = width;
	screenHeight = height;
	boxWidth = 600;
	boxHeight = 800;
	background = LoadTexture("resources/img/background.png");
	box = LoadTexture("resources/img/box2.png");
	mydroppeur = new droppeur();
	currentFruit = getRandomFruit(numberOfFruits);
	fruits = std::vector<fruit*>();

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

void game::update()
{
	while (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		mydroppeur->updateX();
		currentFruit->updateX();
		draw();
	}
	currentFruit->setFalling(true);
	DoFall(currentFruit);

	/*for (int i = 830; i > 100; i--) {
		for (fruit* f : fruits)
		{
			if (f == currentFruit)
				continue;
			if (f->y == i) {
				f->setFalling(true);
				f->setFall(false);
				DoFall(f);
			}
		}
	}*/

	if (currentFruit->getIsFall())
	{
		fruits.push_back(currentFruit);
		currentFruit = getRandomFruit(numberOfFruits);
		numberOfFruits++;
	}

}

void game::DoFall(fruit* fallenFruit)
{
	while (!fallenFruit->getIsFall() && fallenFruit->getIsFalling()) {
		fallenFruit->fall(fruits);

		if (fallenFruit->aEffacer) {
			numberOfFruits--;
			delete fallenFruit;
			fallenFruit = fruits[fruits.size() - 1];
			fruits.pop_back();
			currentFruit = fallenFruit;
			for (fruit* f : fruits)
			{
				if (f->aEffacer)
				{
					fruits.erase(std::remove(fruits.begin(), fruits.end(), f), fruits.end());
					delete f;
					f = nullptr;
				}
			}
		}
		mydroppeur->updateX();
		draw();
	}
}

fruit* game::getRandomFruit(int f) {
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