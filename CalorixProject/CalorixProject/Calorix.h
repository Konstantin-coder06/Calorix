#pragma once
#include <ostream>
#include <vector>
#include "User.h"
#include "Food.h"
#include "Exercise.h"
class Calorix {
	char* name;

	std::vector<User> users;
	std::vector<Food> foods;
	std::vector<Exercise> exercises;

	User* currentUser;

public:
	std::ostream readFromFile(const char* fileName);
	std::ifstream writeInFile(const char* fileName);

	bool registerUser(std::string username, std::string password, int age, double weight, double height, bool gender);
	bool isUsernameTaken(const std::string& name);
	bool login(std::string username, std::string password);
	bool logout();
};