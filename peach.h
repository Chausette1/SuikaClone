#pragma once
#include "fruit.h"
#include "pamplemousse.h"

class peach : public fruit {
public:
    peach();
    ~peach();
   virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit) override;
};
