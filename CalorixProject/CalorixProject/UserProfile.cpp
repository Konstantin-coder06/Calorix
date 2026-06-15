#include "UserProfile.h"
#include <stdexcept>

UserProfile::UserProfile(int age, double weight, double height, bool gender)
{
    if (age <= 0) {
        throw std::invalid_argument("Age must be positive");
    }

    if (weight <= 0) {
        throw std::invalid_argument("Weight must be positive");
    }

    if (height <= 0) {
        throw std::invalid_argument("Height must be positive");
    }

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

int UserProfile::getAge() const
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



