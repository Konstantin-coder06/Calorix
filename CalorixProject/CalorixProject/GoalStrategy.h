#pragma once
#include "UserProfile.h"
class GoalStrategy {
public:
	virtual ~GoalStrategy() = default;
	virtual double calculateTargetCalories(const UserProfile& profile)const = 0;
};