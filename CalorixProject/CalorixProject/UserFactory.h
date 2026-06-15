#pragma once
#include <memory>
#include "User.h"
class UserFactory {
public:
	static std::shared_ptr<User> createTrainee(const std::string& username,
        const std::string& password,
        const UserProfile& profile);

    static std::shared_ptr<User> createAdmin(
        const std::string& username,
        const std::string& password,
        const UserProfile& profile);
};