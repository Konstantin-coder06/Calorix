#pragma once
#include <string>
#include "MuscleGroup.h"

class Admin {
public:
	void blockUser(std::string username);
	void addFood(std::string name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g);
	void addExercise(std::string name, double caloriesBurnedPerHour, MuscleGroup muscleGroup);
	void updateFood(std::string foodName, double newColories);
};