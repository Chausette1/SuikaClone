#pragma once
#include "fruit.h"
#include "watermelon.h"
#include "game.h"

class melon : public fruit {
public:
	melon();
	~melon();
	virtual fruit* Fusion(fruit* otherFruit) override;
};