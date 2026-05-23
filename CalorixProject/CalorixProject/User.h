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
	User(const std::string username, const std::string password, UserProfile profile);
	User() = default;

	void help();

	std::string getName();
	std::string getPassword();
	UserProfile getProfile();
};