#pragma once
#include <string>
#include "MuscleGroup.h"
#include "User.h"
#include <memory>
#include "Food.h"
#include "Exercise.h"
class Admin: public User {
public:
	Admin(std::string name, std::string password, UserProfile userProfile);
	void blockUser(const std::string& username);

	void addFood(std::shared_ptr<Food> food);
	void addExercise(std::shared_ptr<Exercise> exercise);

	void updateFood(const std::string& name, double newCalories);
	bool isAdmin()const override;
};