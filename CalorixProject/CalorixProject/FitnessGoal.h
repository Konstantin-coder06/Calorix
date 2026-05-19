#pragma once
#include "GoalType.h"
#include <string>
class FitnessGoal {
	GoalType goalType;
	int targetValue;
	Date startDate;
	Date endDate;
	bool isAchieved;
public:
	FitnessGoal(GoalType goalType, int targetValue, Date endDate);
};