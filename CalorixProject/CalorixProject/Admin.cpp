#include "Admin.h"

Admin::Admin(std::string name, std::string password, UserProfile userProfile):User(name,password,userProfile)
{
}

bool Admin::isAdmin() const
{
	return true;
}


