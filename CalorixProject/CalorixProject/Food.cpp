#include "Food.h"
#include <stdexcept>
int Food::idCounter = 1;
Food::Food(std::string name, double calories, double protein, double carbs, double fat):name(name)
{
    if (calories <= 0) {
        throw std::invalid_argument("Calories must be positive");
    }
    if (protein < 0) {
        throw std::invalid_argument("Protein cannot be negative");
    }
    if (carbs < 0) {
        throw std::invalid_argument("Carbs  cannot be negative");
    }
    if (fat < 0) {
        throw std::invalid_argument("Fats  cannot be negative");
    }
    this->caloriesPer100g = calories;
    this->proteinPer100g = protein;
    this->carbsPer100g = carbs;
    this->fatPer100g = fat;
    foodId = idCounter;
    idCounter++;
}

std::string Food::getName() const
{
    return name;
}

double Food::getCalories()const
{
    return caloriesPer100g;
}

double Food::getProtein()const
{
    return proteinPer100g;
}

double Food::getCarbs()const
{
    return carbsPer100g;
}

double Food::getFat()const
{
    return fatPer100g;
}

void Food::setNewCalories(double newCaloriesPer100g)
{
    if (newCaloriesPer100g <= 0) {
        throw std::invalid_argument("Calories must be positive");
    }
    this->caloriesPer100g = newCaloriesPer100g;
}
