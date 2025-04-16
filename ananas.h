#pragma once
#include "fruit.h"
#include "melon.h"
class ananas : public fruit
{
public:
	ananas();
	~ananas();
	virtual fruit* Fusion(fruit* otherFruit) override;
};

