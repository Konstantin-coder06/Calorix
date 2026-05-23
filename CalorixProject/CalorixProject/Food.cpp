#include "Food.h"

Food::Food(std::string name, double calories, double protein, double carbs, double fat)
{
}

double Food::getCalories()
{
    return caloriesPer100g;
}

double Food::getProtein()
{
    return proteinPer100g;
}

double Food::getCarbs()
{
    return carbsPer100g;
}

double Food::getFat()
{
    return fatPer100g;
}
