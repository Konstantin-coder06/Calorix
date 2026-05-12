#include "Calorix.h"
#include <iostream>

bool Calorix::registerUser(const std::string username, const std::string password, int age, double weight, double height, bool gender)
{
    if (isUsernameTaken(username)) {
        return false;
    }
    else {     
        users.push_back(User(username, password, UserProfile(age, weight, height, gender)));

        currentUser = &users.back();

        return true;
    }
}

bool Calorix::isUsernameTaken(const std::string& name)
{
    for (auto& user : users) {
        if (user.getName() == name) {
            return true;
        }
    }
    return false;
}

bool Calorix::login(std::string username, std::string password)
{
    if (currentUser != nullptr) {
        std::cout<<"You are already loged in";
        return false;
    }

    for (auto& user : users) {
        if (user.getName() == username) {
            if (user.getPassword() == password) {
                currentUser = &user;
                return true;
            }
        }
    }
    return false;
}

bool Calorix::logout()
{
    if (currentUser == nullptr) {
        return false;
    }
    currentUser = nullptr;
    return true;
}


