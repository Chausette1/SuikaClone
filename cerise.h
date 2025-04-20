#pragma once

#include "fruit.h"
#include "fraise.h"

class cerise : public fruit
{
public:
	cerise();
	~cerise();
	virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit) override;
};

