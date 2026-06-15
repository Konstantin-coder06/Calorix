#pragma once
#include "Activity.h"
class UserProfile {
	int age;
	double weight;
	double height;
	bool gender;
	Activity activityLevel;
public:
	UserProfile(int age, double weight, double height, bool gender);
	UserProfile() = default;

	double getWeight() const;
	double getHeight() const;
	int getAge() const;
	bool getGender() const;

	void setWeight(double weight);
	void setActivityLevel(Activity activity);
};