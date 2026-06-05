#pragma once
#include <ostream>
#include <vector>
#include "User.h"
#include "Food.h"
#include "Exercise.h"
class Calorix {
	char* name;

	std::vector<std::shared_ptr<User>> users;
	std::vector<Food> foods;
	std::vector<Exercise> exercises;

	std::shared_ptr<User> currentUser;

public:
	std::ostream readFromFile(const char* fileName);
	std::ifstream writeInFile(const char* fileName);

	bool registerUser(std::string username, std::string password, int age, double weight, double height, bool gender);
	bool isUsernameTaken(const std::string& name);
	bool login(std::string username, std::string password);
	bool logout();

	bool blockUser(std::string username);
	void addFood(std::string name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g);
	void addExercise(std::string name, double caloriesBurnedPerHour, MuscleGroup muscleGroup);
	bool updateFood(std::string foodName, double newCalories);
};