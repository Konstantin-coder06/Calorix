#include "WorkoutPlan.h"
#include <stdexcept>
void WorkoutPlan::addExercise(std::shared_ptr<Exercise> exercise)
{
	exercises.push_back(exercise);
}

std::vector<std::shared_ptr<Exercise>> WorkoutPlan::getExercises() const
{
	return exercises;
}

double WorkoutPlan::getTotalCalories() const
{
	return totalCalories;
}

int WorkoutPlan::getTotalDuration() const
{
	return totalDuration;
}

void WorkoutPlan::setTotalCalories(double calories)
{
	if (calories <= 0) {
		throw std::invalid_argument("Calories must be positive");
	}
	totalCalories = calories;
}

void WorkoutPlan::setTotalDuration(int duration)
{
	if (duration <= 0) {
		throw std::invalid_argument("Duration must be positive");
	}
	totalDuration = duration;
}
