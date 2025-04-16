#pragma once
#include "fruit.h"
#include "peach.h"

class pomme : public fruit {
public:
    pomme();
    ~pomme();
   virtual fruit* Fusion(fruit* otherFruit) override;
};
