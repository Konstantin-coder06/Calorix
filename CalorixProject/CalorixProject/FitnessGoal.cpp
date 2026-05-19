#include "FitnessGoal.h"
#include "Date.h"

FitnessGoal::FitnessGoal(GoalType goalType, int targetValue, Date endDate)
{
	this->goalType = goalType;
	this->targetValue = targetValue;
	this->endDate = endDate;
}
