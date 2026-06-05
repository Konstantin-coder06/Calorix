#pragma once
#include <string>
#include "MuscleGroup.h"
#include "User.h"
class Admin: public User {
public:
	Admin(std::string name, std::string password, UserProfile userProfile);
	bool isAdmin()const override;
};