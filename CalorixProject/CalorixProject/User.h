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
	User(const std::string& username, const std::string& password,const  UserProfile& profile);
	User() = default;
	virtual ~User() = default;

	void help() const;

	std::string getName() const;
	std::string getPassword() const;
	UserProfile getProfile() const;

	virtual bool isAdmin()const = 0;
};