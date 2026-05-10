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

};