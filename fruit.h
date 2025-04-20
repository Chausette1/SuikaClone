#pragma once

#include "include.h"

class fruit : public std::enable_shared_from_this<fruit>
{
private:
	void ManageFruitOverlap(std::shared_ptr<fruit> sender);
	void DoCollision(std::vector<std::shared_ptr<fruit>>& listFruits, std::shared_ptr<fruit> f);
	bool ManageFruitXCollision();
	void CheckIfHitBoxesAreHit();
	bool ManageCollision(std::shared_ptr<fruit> newCollision);
	Rectangle leftEdge = { 19, 0 ,100, 1000 };
	Rectangle RightEdge = { 679, 0 , 100, 1000 };
	Rectangle BottomEdge = { 0, 850,1000 , 100 };
	std::shared_ptr<fruit> lastCollision;

protected:

	int speed;
	int radius;
	bool isFalling;
	bool isFall;
	Texture2D sprite;
	int angle;
	bool Collision;
	std::shared_ptr<fruit> currentCollision;
	std::vector<std::shared_ptr<fruit>> listCollision;
	fruit();

public:
	void virtual draw();
	void virtual fall(std::vector<std::shared_ptr<fruit>>& listFruits);
	bool virtual getIsFalling();
	void virtual setFalling(bool fall);
	void virtual setFall(bool fall);
	bool virtual getIsFall();
	void virtual updateX();
	bool virtual IsColliding(std::shared_ptr<fruit> otherFruit);
	bool virtual IsFusion(std::shared_ptr<fruit> otherFruit);
	virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit);
	bool virtual DoFusion(std::shared_ptr<fruit> f, std::vector<std::shared_ptr<fruit>>& listFruits);
	void EndFall();
	int x;
	int y;
	virtual ~fruit();
	bool aEffacer;
};