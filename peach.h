#pragma once
#include "fruit.h"
#include "pamplemousse.h"

class peach : public fruit {
public:
    peach();
    ~peach();
   virtual fruit* Fusion(fruit* otherFruit) override;
};
