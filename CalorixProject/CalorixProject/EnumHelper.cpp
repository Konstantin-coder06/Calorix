#include "EnumHelper.h"
#include <stdexcept>
//Back,
//Legs,
//Shoulders,
//Arms,
//Core,
//Cardio
MuscleGroup EnumHelper::stringToMuscleGroup(std::string muscleGroup)
{
    if (muscleGroup == "Chest") {
        return MuscleGroup::Chest;
    }
    if (muscleGroup == "Back") {
        return MuscleGroup::Back;
    }
    if (muscleGroup == "Legs") {
        return MuscleGroup::Legs;
    }
    if (muscleGroup == "Shoulders") {
        return MuscleGroup::Shoulders;
    }
    if (muscleGroup == "Arms") {
        return MuscleGroup::Arms;
    }
    if (muscleGroup == "Core") {
        return MuscleGroup::Core;
    }
    if (muscleGroup == "Cardio") {
        return MuscleGroup::Cardio;
    }

    throw std::invalid_argument("Invalid muscle group");
}

std::string EnumHelper::muscleGroupToString(const MuscleGroup& muscleGroup)
{
    switch (muscleGroup)
    {
    case MuscleGroup::Chest: return "Chest";
    case MuscleGroup::Back: return "Back";
    case MuscleGroup::Legs: return "Legs";
    case MuscleGroup::Shoulders: return "Shoulders";
    case MuscleGroup::Arms: return "Arms";
    case MuscleGroup::Core: return "Core";
    case MuscleGroup::Cardio: return "Cardio";
    default: return "Unknown";
    }
}
//Sedentary,
//Light,
//Moderate,
//Active,
//Very_Active
Activity EnumHelper::stringToActivity(const std::string& activity)
{
    if (activity == "Sedentary") {
        return Activity::Sedentary;
    }
    if (activity == "Light") {
        return Activity::Light;
    }
    if (activity == "Moderate") {
        return Activity::Moderate;
    }
    if (activity == "Active") {
        return Activity::Active;
    }
    if (activity == "Very Active") {
        return Activity::Very_Active;
    }
    throw std::invalid_argument("Invalid Activity");
}

std::string EnumHelper::activityToString(const Activity& activity)
{
    switch (activity) {
    case Activity::Sedentary: return "Sedentary";break;
    case Activity::Light: return "Light";break;
    case Activity::Moderate: return "Moderate";break;
    case Activity::Active:return "Active";break;
    case Activity::Very_Active:return "Very Active";break;
    default: return "Unknown";
    }
}
//WeightLoss,
//Bulking,
//Maintenance
GoalType EnumHelper::stringToGoalType(const std::string& goalType)
{
    if (goalType == "WeightLoss") {
        return GoalType::WeightLoss;
    }
    if (goalType == "Bulking") {
        return GoalType::Bulking;
    }
    if (goalType == "Maintenance") {
        return GoalType::Maintenance;
    }
    throw std::invalid_argument("Invalid Goal Type");

}

std::string EnumHelper::goalTypeToString(const GoalType& goalType)
{
    switch (goalType) {
    case GoalType::WeightLoss: return "WeightLoss";break;
    case GoalType::Bulking:return "Bulking";break;
    case GoalType::Maintenance:return "Maintenance";break;
    default:return "Unknown";
    }
}

Gender EnumHelper::stringToGender(const std::string& gender)
{
    if (gender == "Male") {
        return Gender::Male;
    }
    if (gender == "Female") {
        return Gender::Female;
    }
    throw std::invalid_argument("Invalid Gender");
}

std::string EnumHelper::genderToString(const Gender& gender)
{
    switch (gender) {
    case Gender::Male:return "Male";break;
    case Gender::Female:return "Female";break;
    default:return "Unknown";
    }
}

