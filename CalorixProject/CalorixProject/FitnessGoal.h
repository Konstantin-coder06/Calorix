#pragma once
#include "GoalType.h"
#include <string>
class FitnessGoal {
	GoalType goalType;
	double targetValue;
	std::string startDate;
	std::string endDate;
	bool isAchieved;
};