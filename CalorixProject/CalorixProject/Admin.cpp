#include "Admin.h"
#include <iostream>

Admin::Admin(std::string name, std::string password, UserProfile userProfile):User(name,password,userProfile)
{
}

bool Admin::isAdmin() const
{
	return true;
}

void Admin::help() const
{
    std::cout << "Admin commands:" << std::endl;
    std::cout << "block-user" << std::endl;
    std::cout << "add-food" << std::endl;
    std::cout << "add-exercise" << std::endl;
    std::cout << "update-food" << std::endl;
}


