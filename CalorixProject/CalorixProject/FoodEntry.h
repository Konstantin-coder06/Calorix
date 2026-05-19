#pragma once
#include <string>
#include "Food.h"
#include "Date.h"
class FoodEntry {
	int entryId;
	static int idCounter;
	Food& food;
	double quantityGrams;
	Date date;
public:
	FoodEntry(Food& food, double quantityGrams);
	FoodEntry() = default;

	FoodEntry(Food& food, double quantityGrams,Date date);
	bool isValidQuantity(double quantity);
};