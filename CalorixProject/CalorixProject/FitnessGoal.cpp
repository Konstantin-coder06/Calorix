#include "FitnessGoal.h"
#include "Date.h"
#include <stdexcept>
FitnessGoal::FitnessGoal(GoalType goalType, double targetValue, Date startDate, Date endDate) :goalType(goalType), startDate(startDate), endDate(endDate), isAchieved(false)
{
	if (targetValue > 150 || targetValue < 40) {
		throw std::invalid_argument("Target must be in the interval [40,150]");
	}
	this->targetValue = targetValue;
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

Date FitnessGoal::getStartDate() const
{
	return startDate;
}

Date FitnessGoal::getEndDate() const
{
	return endDate;
}

void FitnessGoal::setIsAchieved()
{
	isAchieved = true;
}
