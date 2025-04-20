#pragma once
#include "fruit.h"
#include "melon.h"
class ananas : public fruit
{
public:
	ananas();
	~ananas();
	virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit) override;
};

