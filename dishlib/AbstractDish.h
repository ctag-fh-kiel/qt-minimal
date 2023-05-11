#pragma once

#include <iostream>

namespace dishlib{
    class AbstractDish {
    public:
        virtual void Cook() const = 0;
        virtual ~AbstractDish() = default;
    };
}

