#include "Food.h"

int Food::idCounter = 0;
Food::Food(std::string name, double calories, double protein, double carbs, double fat):name(name),caloriesPer100g(calories),
          proteinPer100g(protein),carbsPer100g(carbs),fatPer100g(fat)
{
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
    this->caloriesPer100g = newCaloriesPer100g;
}
