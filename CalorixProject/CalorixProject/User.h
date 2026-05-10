#pragma once
#include <string>
#include "UserProfile.h"
class User {
	int userId;
	static int idCounter;
	std::string username;
	std::string password;
	UserProfile profile;
public:
	void registerUser(std::string username, std::string password, int age, double weight, double height, bool genre);
	void login(std::string username, std::string password);
	void logout();
	void help();
};