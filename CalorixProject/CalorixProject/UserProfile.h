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
public:
	UserProfile(int age, double weight, double height, bool gender);
	UserProfile() = default;

	double getWeight() const;
	double getHeight() const;
	double getAge() const;
	bool getGender() const;
};