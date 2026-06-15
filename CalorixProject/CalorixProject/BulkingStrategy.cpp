#include "BulkingStrategy.h"
#include "UserProfile.h"

double BulkingStrategy::calculateTargetCalories(double bmr) const
{
    return bmr +300;
}
