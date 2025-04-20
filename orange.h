#pragma once
#include "fruit.h"
#include "pomme.h"

class orange : public fruit {
public:
    orange();
    ~orange();
   virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit) override;
};