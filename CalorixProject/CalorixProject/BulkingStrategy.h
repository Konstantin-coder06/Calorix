#pragma once
#include "GoalStrategy.h"
#include "UserProfile.h" 

class BulkingStrategy :public GoalStrategy {
public:
	double calculateTargetCalories(double bmr)const override;
};