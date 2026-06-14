#include "User.h"
#include <iostream>
int User::idCounter = 1;

User::User(const std::string& username, const std::string& password, const UserProfile& profile)
{
	this->userId = idCounter;
	this->username = username;
	this->password = password;
	this->profile = profile;

	idCounter++;
}

void User::help() const
{
	std::cout << "Available commands:\n";
	std::cout << "register\n";
	std::cout << "login\n";
	std::cout << "logout\n";
}

std::string User::getName() const
{
	return username;
}

std::string User::getPassword() const
{
	return password;
}

UserProfile User::getProfile() const
{
	return profile;
}
