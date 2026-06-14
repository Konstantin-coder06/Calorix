#pragma once
#include <vector>
#include <memory>
#include "Exercise.h"
class WorkoutPlan {
	std::vector<std::shared_ptr<Exercise>> exercises;
	double totalCalories;
	int totalDuration;
public:
	void addExercise(std::shared_ptr<Exercise>exercise);
	std::vector<std::shared_ptr<Exercise>> getExercises()const;

	double getTotalCalories()const;
	int getTotalDuration()const;

	void setTotalCalories(double calories);
	void setTotalDuration(int duration);
};