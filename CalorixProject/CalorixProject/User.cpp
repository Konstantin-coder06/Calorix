#include "User.h"
#include <iostream>
int User::idCounter = 1;

User::User(const std::string& username, const std::string& password, const UserProfile& profile):username(username),password(password),profile(profile)
{
	userId = idCounter;
	idCounter++;
}

std::string User::getName() const
{
	return username;
}

std::string User::getPassword() const
{
	return password;
}

const UserProfile& User::getProfile() const
{
	return profile;
}
