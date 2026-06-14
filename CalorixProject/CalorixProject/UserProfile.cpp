#include "UserProfile.h"
#include <stdexcept>

UserProfile::UserProfile(int age, double weight, double height, bool gender)
{
	this->age = age;
	this->weight = weight;
	this->height = height;
	this->gender = gender;
	this->activityLevel = Activity::Sedentary;
}

double UserProfile::getWeight() const
{
	return weight;
}

double UserProfile::getHeight() const
{
	return height;
}

double UserProfile::getAge() const
{
	return age;
}

bool UserProfile::getGender() const
{
	return gender;
}

void UserProfile::setWeight(double weight)
{
	if (weight <= 0) {
		throw std::invalid_argument("Weight must be positive");
	}
	this->weight = weight;
}

void UserProfile::setActivityLevel(Activity activity)
{
	activityLevel = activity;
}



