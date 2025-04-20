#pragma once
#include "fruit.h"
#include "mandarine.h"
class raisin : public fruit
{
public:
	raisin();
	~raisin();
	virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit) override;
};