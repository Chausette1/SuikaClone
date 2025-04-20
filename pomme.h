#pragma once
#include "fruit.h"
#include "peach.h"

class pomme : public fruit {
public:
	pomme();
	~pomme();
	virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit, int& score) override;
};
