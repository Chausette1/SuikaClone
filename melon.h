#pragma once
#include "fruit.h"
#include "watermelon.h"

class melon : public fruit {
public:
    melon();
    ~melon();
    virtual fruit* Fusion(fruit* otherFruit) override;
};