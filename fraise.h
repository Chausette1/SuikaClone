#pragma once
#include "fruit.h"
#include "raisin.h"

class fraise : public fruit
{
public:
	fraise();
	~fraise();
	virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit, int& score) override;
};