#include "FoodEntry.h"

FoodEntry::FoodEntry(Food& food, double quantityGrams) 
	:food(food), 
	quantityGrams(quantityGrams){}

Food& FoodEntry::getFood()
{
	return food;
}

double FoodEntry::getQuantityGrams()
{
	return quantityGrams;
}

bool FoodEntry::isValidQuantity(double quantity)
{

	return quantity<1;
}

