#pragma once
#include "GoalStrategy.h"
#include "UserProfile.h"

class MaintenanceStrategy :public GoalStrategy {
public:
	double calculateTargetCalories(double bmr) const override;
};