#include "Exercise.h"

Exercise::Exercise(std::string name, double calBurn, MuscleGroup muscle)
{
	this->name = name;
	this->caloriesBurnedPerHour = calBurn;
	this->muscleGroup = muscle;
}
