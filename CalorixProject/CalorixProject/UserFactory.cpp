#include "UserFactory.h"
#include "Trainee.h"
#include <memory>
#include "Admin.h"
std::shared_ptr<User> UserFactory::createTrainee(const std::string& username, const std::string& password, const UserProfile& profile)
{
    return std::make_shared<Trainee>(username,password,profile);
}

std::shared_ptr<User> UserFactory::createAdmin(const std::string& username, const std::string& password, const UserProfile& profile)
{
    return std::make_shared<Admin>(username,password,profile);
}
