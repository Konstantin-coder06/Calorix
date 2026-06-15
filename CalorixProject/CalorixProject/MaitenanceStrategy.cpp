#include "MaitenanceStrategy.h"

double MaitenanceStrategy::calculateTargetCalories(const UserProfile& profile) const
{
    double weight = profile.getWeight();
    double height = profile.getWeight();
    int age = profile.getAge();
    double bmr = 0;
    if (profile.getGender() == true) {

        bmr = 10 * weight + 6.25 * height - 5 * age + 5;
    }
    else {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161;
    }
    return bmr;
}
