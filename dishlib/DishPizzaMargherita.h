#pragma once
#include "AbstractDish.h"

namespace dishlib{
    class DishPizzaMargherita : public AbstractDish{
    public:
        void Cook() const override;
    };
}
