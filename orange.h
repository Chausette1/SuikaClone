#pragma once
#include "fruit.h"
#include "pomme.h"

class orange : public fruit {
public:
    orange();
    ~orange();
   virtual fruit* Fusion(fruit* otherFruit) override;
};