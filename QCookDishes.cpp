#include "QCookDishes.h"
#include <iostream>
#include <memory>
#include "DishFactory.h"

void QCookDishes::startCooking(){
    std::cout << "Starting cooking..." << std::endl;
    emit cooking_step("Starting cooking");
    std::unique_ptr<dishlib::AbstractDish> dish {std::make_unique<dishlib::DishBratwurst>()};
    dish->Cook();
    emit cooking_step("Cooked Bratwurst");
}