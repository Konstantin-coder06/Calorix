#pragma once
#include "GoalStrategy.h"
class BulkingStrategy :public GoalStrategy {
public:
	double calculateTargetCalories(const UserProfile& profile)const override;
};