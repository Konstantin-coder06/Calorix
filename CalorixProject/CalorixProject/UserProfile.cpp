#include "UserProfile.h"

UserProfile::UserProfile(int age, double weight, double height, bool gender)
{
	this->age = age;
	this->weight = weight;
	this->height = height;
	this->gender = gender;
	this->activityLevel = Activity::Sedentary;
}


