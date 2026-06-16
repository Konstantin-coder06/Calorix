#pragma once
#include "GoalType.h"
#include "Date.h"
class FitnessGoal {
	GoalType goalType;
	double targetValue;
	Date startDate;
	Date endDate;
	bool isAchieved;
public:
	FitnessGoal(GoalType goalType, double targetValue,Date startDate, Date endDate);

	GoalType getGoalType()const;
	bool getIsAchieved() const;
	double getTargetValue() const;
	Date getStartDate()const;
	Date getEndDate()const;

	void setIsAchieved();
};