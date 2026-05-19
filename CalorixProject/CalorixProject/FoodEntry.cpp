#include "FoodEntry.h"

FoodEntry::FoodEntry(Food& food, double quantityGrams) 
	:food(food), 
	quantityGrams(quantityGrams){}

bool FoodEntry::isValidQuantity(double quantity)
{

	return quantity<1;
}

