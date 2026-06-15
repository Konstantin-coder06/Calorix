#include "FoodEntry.h"
#include <memory>


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
	return quantity >= 1;
}

double FoodEntry::calculateCalories() const
{
	if (!food) {
		return 0.0;
	}
	return food->getCalories() * quantityGrams / 100;
}

