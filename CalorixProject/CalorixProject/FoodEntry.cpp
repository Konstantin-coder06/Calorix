#include "FoodEntry.h"
#include <memory>
#include <stdexcept>
int FoodEntry::idCounter = 1;
std::shared_ptr<Food> FoodEntry::getFood() const
{
	return food;
}

double FoodEntry::getQuantityGrams()const
{
	return quantityGrams;
}

FoodEntry::FoodEntry(std::shared_ptr<Food> food, double quantityGrams, const Date& date) :food(food), date(date)
{
	if (quantityGrams <= 0) {
		throw std::invalid_argument("Quantity must be positive");
	}
	if (!this->food) {
		throw std::invalid_argument("Food cannot be null");
	}
	this->quantityGrams = quantityGrams;
	entryId = idCounter++;
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

Date FoodEntry::getDate() const
{
	return date;
}

