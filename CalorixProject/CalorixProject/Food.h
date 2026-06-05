#pragma once
#include <string>
class Food {
	int foodId;
	static int idCounter;
	std::string name;
	double caloriesPer100g;
	double proteinPer100g;
	double carbsPer100g;
	double fatPer100g;
public:
	Food() = default;
	Food(std::string name, double calories, double protein, double carbs, double fat);
	~Food() = default;
	Food(const Food& other) = default;
	Food& operator=(const Food& other) = default;

	std::string getName()const;
	double getCalories() const;
	double getProtein() const;
	double getCarbs() const;
	double getFat() const;

	void setNewCalories(double newCaloriesPer100g);
};