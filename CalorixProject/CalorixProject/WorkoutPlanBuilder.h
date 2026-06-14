#pragma once
#include <vector>
#include <memory>
#include "Exercise.h"
class WorkoutPlanBuilder {
	std::vector<std::shared_ptr<Exercise>> availableExercises;
public:
	WorkoutPlanBuilder(std::vector<std::shared_ptr<Exercise>>exercises);
};