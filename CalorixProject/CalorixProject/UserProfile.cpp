#include "UserProfile.h"
#include <stdexcept>

UserProfile::UserProfile(int age, double weight, double height, const Gender& gender)
{
    if (age <= 0) {
        throw std::invalid_argument("Age must be positive");
    }
    if (age >= 100) {
        throw std::invalid_argument("Age must be less than 100");
    }
    if (weight <= 0) {
        throw std::invalid_argument("Weight must be positive");
    }
    if (weight >= 300) {
        throw std::invalid_argument("Weight must be less than 300 kg");
    }
    if (height <= 0) {
        throw std::invalid_argument("Height must be positive");
    }
    if (height >= 250) {
        throw std::invalid_argument("Height must be less than 250 cm");
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

Gender UserProfile::getGender() const
{
	return gender;
}

void UserProfile::setWeight(double weight)
{
	if (weight <= 0) {
		throw std::invalid_argument("Weight must be positive");
	}
    if (weight >= 300) {
        throw std::invalid_argument("Weight must be less than 300 kg");
    }
	this->weight = weight;
}

void UserProfile::setActivityLevel(Activity activity)
{
	activityLevel = activity;
}



