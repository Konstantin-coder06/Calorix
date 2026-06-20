#include "Exercise.h"
#include <stdexcept>
int Exercise::idCounter = 1;
Exercise::Exercise(std::string name, double calBurn, MuscleGroup muscle):name(name),muscleGroup(muscle)
{
	if (calBurn <= 0) {
		throw std::invalid_argument("Calories burned must be positive");
	}
	caloriesBurnedPerHour = calBurn;
	exerciseId = idCounter;
	idCounter++;
}

std::string Exercise::getName()const
{
	return name;
}

double Exercise::getCaloriesBurned() const
{
	return caloriesBurnedPerHour;
}

MuscleGroup Exercise::getMuscleGroup() const
{
	return muscleGroup;
}
