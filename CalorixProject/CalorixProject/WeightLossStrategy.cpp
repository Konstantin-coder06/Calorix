#include "WeightLossStrategy.h"

double WeightLossStrategy::calculateTargetCalories(double bmr) const
{
    double result = bmr - 500;
    return result < 1200 ? 1200 : result;
}
