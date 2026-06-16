#pragma once
#include "Activity.h"
#include "Gender.h"
class UserProfile {
	int age;
	double weight;
	double height;
	Gender gender;
	Activity activityLevel;
public:
	UserProfile(int age, double weight, double height, const Gender& gender);
	UserProfile() = default;

	double getWeight() const;
	double getHeight() const;
	int getAge() const;
	Gender getGender() const;

	void setWeight(double weight);
	void setActivityLevel(Activity activity);
};