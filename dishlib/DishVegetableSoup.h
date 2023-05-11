#pragma once

#include <AbstractDish.h>

namespace dishlib{
    class DishVegetableSoup : public AbstractDish{
        void Cook() const override;
    };
}