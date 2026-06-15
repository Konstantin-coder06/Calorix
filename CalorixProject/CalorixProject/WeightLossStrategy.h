#pragma once
#include "GoalStrategy.h"
#include "UserProfile.h"

class WeightLossStrategy :public GoalStrategy {
public:
	double calculateTargetCalories(double bmr)const override;
};