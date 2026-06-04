#include "FoodEntry.h"
#include <memory>

FoodEntry::FoodEntry(std::shared_ptr<Food> food, double quantityGrams)
	:food(food), 
	quantityGrams(quantityGrams){}

std::shared_ptr<Food> FoodEntry::getFood() const
{
	return food;
}

double FoodEntry::getQuantityGrams()const
{
	return quantityGrams;
}

bool FoodEntry::isValidQuantity(double quantity)
{

	return quantity<1;
}

