#pragma once
#include "fruit.h"
#include "ananas.h"

class pamplemousse : public fruit {
public:
	pamplemousse();
	~pamplemousse();
	virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit, int& score) override;
};