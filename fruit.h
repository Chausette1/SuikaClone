#pragma once

#include "include.h"

class fruit
{
private:
	void ManageFruitOverlap();
	void DoCollision(std::vector<fruit*> listFruits);
	void ManageFruitXCollision();
	void CheckIfHitBoxesAreHit();
	void ManageMultipleCollision(fruit* newCollision, std::vector<fruit*> listFruits);
	Rectangle leftEdge = { 19, 0 ,100, 1000 };
	Rectangle RightEdge = { 679, 0 , 100, 1000 };
	Rectangle BottomEdge = { 0, 850,1000 , 100 };

protected:
	
	int speed;
	int radius;
	bool isFalling;
	bool isFall;
	Texture2D sprite;
	int angle;
	bool Collision;
	fruit* currentCollision;
	std::vector<fruit*> listCollision;
	fruit();
	

public:
	void virtual draw();
	void virtual fall(std::vector<fruit*> listFruits);
	bool virtual getIsFalling();
	void virtual setFall(bool fall);
	bool virtual getIsFall();
	void virtual updateX();
	bool virtual IsColliding(fruit* otherFruit);
	bool virtual IsFusion(fruit * otherFruit);
	virtual fruit* Fusion(fruit* otherFruit) = 0;
	int x;
	int y;
	virtual ~fruit();
	bool aEffacer;


};