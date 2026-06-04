#include "Food.h"

Food::Food(std::string name, double calories, double protein, double carbs, double fat)
{
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
