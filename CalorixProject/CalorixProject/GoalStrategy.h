#pragma once
#include "UserProfile.h"
class GoalStrategy {
public:
	virtual ~GoalStrategy() = default;
	virtual double calculateTargetCalories(double bmr)const = 0;
};