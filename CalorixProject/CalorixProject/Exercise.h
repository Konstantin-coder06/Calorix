#pragma once
#include <string>
#include "MuscleGroup.h"
class Exercise {
	int exerciseId;
	static int idCounter;
	std::string name;
	double caloriesBurnedPerHour;
	MuscleGroup muscleGroup;
};