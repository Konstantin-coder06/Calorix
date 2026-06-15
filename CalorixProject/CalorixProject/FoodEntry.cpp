#include "FoodEntry.h"
#include <memory>
#include <stdexcept>

std::shared_ptr<Food> FoodEntry::getFood() const
{
	return food;
}

double FoodEntry::getQuantityGrams()const
{
	return quantityGrams;
}

FoodEntry::FoodEntry(std::shared_ptr<Food> food, double quantityGrams, Date date) :food(std::move(food)), date(date)
{
	if (quantityGrams <= 0) {
		throw std::invalid_argument("Quantity must be positive");
	}
	this->quantityGrams = quantityGrams;
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

