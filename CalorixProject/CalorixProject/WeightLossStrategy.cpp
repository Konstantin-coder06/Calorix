#include "WeightLossStrategy.h"

double WeightLossStrategy::calculateTargetCalories(double bmr) const
{
    return bmr - 500;
}
