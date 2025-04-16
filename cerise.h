#pragma once
#include "fruit.h"
#include "fraise.h"

class cerise : public fruit
{
public:
	cerise();
	~cerise();
	virtual fruit* Fusion(fruit* otherFruit) override;
};

