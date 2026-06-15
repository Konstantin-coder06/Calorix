#include "FoodEntry.h"
#include <memory>

FoodEntry::FoodEntry(std::shared_ptr<Food> food, double quantityGrams)
	:food(std::move(food)), 
	quantityGrams(quantityGrams){}

std::shared_ptr<Food> FoodEntry::getFood() const
{
	return food;
}

double FoodEntry::getQuantityGrams()const
{
	return quantityGrams;
}

FoodEntry::FoodEntry(std::shared_ptr<Food> food, double quantityGrams, Date date) :food(std::move(food)), quantityGrams(quantityGrams), date(date)
{
}

bool FoodEntry::isValidQuantity(double quantity)
{

	return quantity<1;
}

double FoodEntry::calculateCalories() const
{
	return food->getCalories() * quantityGrams / 100;
}

