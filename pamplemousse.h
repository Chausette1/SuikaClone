#pragma once
#include "fruit.h"
#include "ananas.h"

class pamplemousse : public fruit {
public:
    pamplemousse();
    ~pamplemousse();
   virtual fruit* Fusion(fruit* otherFruit) override;
};