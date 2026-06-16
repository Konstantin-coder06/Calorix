#pragma once
#include "Food.h"
#include "Date.h"
#include <memory>
class FoodEntry {
	int entryId;
	static int idCounter;
	std::shared_ptr<Food> food;
	double quantityGrams;
	Date date;
public:
	
	FoodEntry() = default;
	
	FoodEntry(std::shared_ptr<Food> food, double quantityGrams,Date date);

	std::shared_ptr<Food> getFood() const;
	double getQuantityGrams()const;

	bool isValidQuantity(double quantity);
	double calculateCalories()const;
	Date getDate()const;
};