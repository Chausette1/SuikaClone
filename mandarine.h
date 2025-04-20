#pragma once
#include "fruit.h"
#include "orange.h"

class mandarine : public fruit {
public:
    mandarine();
    ~mandarine();
   virtual std::shared_ptr<fruit> Fusion(std::shared_ptr<fruit> otherFruit) override;
};