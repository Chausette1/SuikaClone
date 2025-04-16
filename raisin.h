#pragma once
#include "fruit.h"
#include "mandarine.h"
class raisin : public fruit
{
public:
	raisin();
	~raisin();
	virtual fruit* Fusion(fruit* otherFruit) override;
};