#pragma once
#include "MuscleGroup.h"
#include <string>
#include "Activity.h"
#include "GoalType.h"
#include "Gender.h"
class EnumHelper {
public:
	static MuscleGroup stringToMuscleGroup(std::string muscleGroup);
	static std::string muscleGroupToString(const MuscleGroup& muscleGroup);

	static Activity stringToActivity(const std::string& activity);
	static std::string activityToString(const Activity& activity);

	static GoalType stringToGoalType(const std::string& goalType);
	static std::string goalTypeToString(const GoalType& goalType);

	static Gender stringToGender(const std::string& gender);
	static std::string genderToString(const Gender& gender);
};