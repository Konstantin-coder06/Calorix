#include "FitnessGoal.h"
#include "Date.h"

FitnessGoal::FitnessGoal(GoalType goalType, double targetValue, Date endDate)
{
	this->goalType = goalType;
	this->targetValue = targetValue;
	this->endDate = endDate;
}

bool FitnessGoal::getIsAchieved()
{
	return isAchieved;
}

double FitnessGoal::getTargetValue()
{
	return targetValue;
}
