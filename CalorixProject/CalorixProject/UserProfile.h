#pragma once
enum class Activity {
	Sedentary,
	Light,
	Moderate,
	Active,
	Very_Active
};
class UserProfile {
	int age;
	double weight;
	double height;
	bool gender;
	Activity activityLevel;
};