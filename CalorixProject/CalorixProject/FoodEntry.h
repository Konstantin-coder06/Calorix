#pragma once
#include <string>
#include "Food.h"
#include "Date.h"
class FoodEntry {
	int entryId;
	static int idCounter;
	std::shared_ptr<Food> food;
	double quantityGrams;
	Date date;
public:
	FoodEntry(std::shared_ptr<Food> food, double quantityGrams);
	FoodEntry() = default;
	std::shared_ptr<Food> getFood() const;
	double getQuantityGrams()const;
	FoodEntry(std::unique_ptr<Food> food, double quantityGrams,Date date);
	bool isValidQuantity(double quantity);
};