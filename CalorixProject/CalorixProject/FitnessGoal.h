#pragma once
#include "GoalType.h"
#include <string>
class FitnessGoal {
	GoalType goalType;
	double targetValue;
	Date startDate;
	Date endDate;
	bool isAchieved;
public:
	FitnessGoal(GoalType goalType, double targetValue, Date endDate);
	bool getIsAchieved() const;
	double getTargetValue() const;
};