#pragma once
#include <string>
#include "MuscleGroup.h"
class Exercise {
	int exerciseId;
	static int idCounter;
	std::string name;
	double caloriesBurnedPerHour;
	MuscleGroup muscleGroup;
public:
	Exercise() = default;
	Exercise(std::string name, double calBurn,MuscleGroup muscle);
	Exercise(const Exercise& other) = default;
	Exercise& operator=(const Exercise& other) = default;

	std::string getName() const;
	double getCaloriesBurned()const;
};