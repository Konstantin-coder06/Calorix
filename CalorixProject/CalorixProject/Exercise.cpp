#include "Exercise.h"

int Exercise::idCounter = 0;
Exercise::Exercise(std::string name, double calBurn, MuscleGroup muscle):name(name),caloriesBurnedPerHour(calBurn),muscleGroup(muscle)
{
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
