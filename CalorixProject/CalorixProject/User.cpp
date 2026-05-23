#include "User.h"
#include <iostream>
int User::idCounter = 1;

User::User(const std::string username, const std::string password, UserProfile profile)
{
	this->userId = idCounter;
	this->username = username;
	this->password = password;
	this->profile = profile;

	idCounter++;
}

void User::help()
{
	std::cout << "Available commands:\n";
	std::cout << "register\n";
	std::cout << "login\n";
	std::cout << "logout\n";
}

std::string User::getName()
{
	return username;
}

std::string User::getPassword()
{
	return password;
}

UserProfile User::getProfile()
{
	return profile;
}
