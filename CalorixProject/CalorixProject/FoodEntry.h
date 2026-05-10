#pragma once
#include <string>
#include "Food.h"
class FoodEntry {
	int entryId;
	static int idCounter;
	Food& food;
	double quantityGrams;
	std::string date;
};