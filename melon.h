#pragma once
#include "fruit.h"
#include "watermelon.h"
#include "game.h"

class melon : public fruit {
public:
	melon();
	~melon();
	virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit, int& score) override;
};