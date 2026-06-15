#pragma once
#include "GoalStrategy.h"
class WeightLossStrategy :public GoalStrategy {
public:
	double calculateTargetCalories(const UserProfile& proifile)const override;
};