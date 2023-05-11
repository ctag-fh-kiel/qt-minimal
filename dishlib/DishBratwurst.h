#pragma once

#include <AbstractDish.h>
namespace dishlib{
    class DishBratwurst: public AbstractDish{
        void Cook() const override;
    };
}
