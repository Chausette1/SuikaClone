#pragma once
#include "fruit.h"
#include "raisin.h"

class fraise : public fruit 
{
public:
    fraise();
    ~fraise();
    virtual fruit* Fusion(fruit* otherFruit) override;
};