#pragma once
#include "fruit.h"
class watermelon : public fruit
{
public:
	watermelon();
	~watermelon();
	virtual fruit* Fusion(fruit* otherFruit) override;
};

