#include "FitnessGoal.h"
#include "Date.h"

FitnessGoal::FitnessGoal(GoalType goalType, double targetValue,Date startDate, Date endDate):goalType(goalType),targetValue(targetValue),startDate(startDate),endDate(endDate), isAchieved(false)
{
}

GoalType FitnessGoal::getGoalType() const
{
	return goalType;
}

bool FitnessGoal::getIsAchieved()const
{
	return isAchieved;
}

double FitnessGoal::getTargetValue()const
{
	return targetValue;
}
