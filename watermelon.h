#pragma once
#include "fruit.h"
class watermelon : public fruit
{
public:
	watermelon();
	~watermelon();
	virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit) override;
};

