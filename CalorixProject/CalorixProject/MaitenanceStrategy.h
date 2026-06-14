#pragma once
#include "GoalStrategy.h"
class MaitenanceStrategy :public GoalStrategy {
public:
	double calculateTargetCalories(const UserProfile& profile)const override;
};