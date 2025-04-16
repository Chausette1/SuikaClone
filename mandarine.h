#pragma once
#include "fruit.h"
#include "orange.h"

class mandarine : public fruit {
public:
    mandarine();
    ~mandarine();
   virtual fruit* Fusion(fruit* otherFruit) override;
};