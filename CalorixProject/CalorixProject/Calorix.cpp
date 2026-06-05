#include "Calorix.h"
#include <iostream>

bool Calorix::registerUser(const std::string username, const std::string password, int age, double weight, double height, bool gender)
{
    if (isUsernameTaken(username)) {
        return false;
    }
    else {     
        users.push_back(std::make_shared<User>(username, password, UserProfile(age, weight, height, gender)));

        currentUser = users.back();

        return true;
    }
}

bool Calorix::isUsernameTaken(const std::string& name)
{
    for (const auto& user : users) {
        if (user->getName() == name) {
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

    for (const auto& user : users) {
        if (user->getName() == username) {
            if (user->getPassword() == password) {
                currentUser = user;
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

bool Calorix::blockUser(std::string username)
{
    auto it = std::find_if(users.begin(), users.end(), [&](const auto& user) {
        return user->getName() == username;
        });

    if (it == users.end()) {
        return false;
    }

    users.erase(it);
    return true;
}

void Calorix::addFood(std::string name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g)
{
    foods.push_back(Food(name, caloriesPer100g, proteinPer100g, carbsPer100g, fatPer100g));
}

void Calorix::addExercise(std::string name, double caloriesBurnedPerHour, MuscleGroup muscleGroup)
{
    exercises.push_back(Exercise(name, caloriesBurnedPerHour, muscleGroup));
}

bool Calorix::updateFood(std::string foodName, double newCalories)
{
    auto it = std::find_if(foods.begin(), foods.end(), [&](const auto& food) {
        return food.getName() == foodName;
        });

    if (it == foods.end()) {
        return false;
    }
    (*it).setNewCalories(newCalories);
    return true;
}


