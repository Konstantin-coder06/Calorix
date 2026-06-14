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
	
	FoodEntry(std::unique_ptr<Food> food, double quantityGrams,Date date);

	std::shared_ptr<Food> getFood() const;
	double getQuantityGrams()const;
	bool isValidQuantity(double quantity);
	double calculateCalories()const;
};