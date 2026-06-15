#include "Calorix.h"
#include <iostream>
#include "UserFactory.h"
#include "Admin.h"
#include <memory>
#include "Trainee.h"

void Calorix::requireLogin() const
{
    if (!currentUser) {
        throw std::runtime_error("You must be logged in");
    }
}

void Calorix::requireAdmin() const
{
    requireLogin();
    if (!std::dynamic_pointer_cast<Admin>(currentUser)) {
        throw std::runtime_error("Admin rights required");
    }
}

void Calorix::requireTrainee() const
{
    requireLogin();
    if (!std::dynamic_pointer_cast<Trainee>(currentUser)) {
        throw std::runtime_error("Trainee rights required");
    }
}

Calorix& Calorix::getInstance()
{
    static Calorix instance;
    return instance;
}

void Calorix::registerUser(const std::string username, const std::string password, int age, double weight, double height, bool gender)
{
    if (isUsernameTaken(username)) {
        throw std::invalid_argument("Username already exists");
    }
        
    users.push_back(UserFactory::createTrainee(username, password, UserProfile(age, weight, height, gender)));
    
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

void Calorix::login(std::string username, std::string password)
{
    if (currentUser != nullptr) {
        std::cout<<"You are already loged in";
    }
    auto user = findUser(username);
    if (!user) {
        throw std::invalid_argument("User is not found");
    }
    if (user->getPassword() != password) {
        throw std::invalid_argument("Wrong password");
    }
    currentUser = user;
}

void Calorix::logout()
{
    if (currentUser == nullptr) {
        throw std::invalid_argument("You must log in");
    }
    currentUser = nullptr;
    
}

void Calorix::blockUser(std::string username)
{
    requireAdmin();
    auto it = std::remove_if(users.begin(), users.end(), [&](const auto& user) {
        return user->getName() == username;
        });

    if (it == users.end()) {
        throw std::invalid_argument("User not found");
    }

    users.erase(it,users.end());
  
}

void Calorix::addFood(std::string name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g)
{
    requireAdmin();
    if (findFood(name)) {
        throw std::invalid_argument("Food already exists");
    }
    foods.push_back(std::make_shared<Food>(name, caloriesPer100g, proteinPer100g, carbsPer100g, fatPer100g));
}

void Calorix::addExercise(std::string name, double caloriesBurnedPerHour, MuscleGroup muscleGroup)
{
    requireAdmin();
    if (findExercise(name)) {
        throw std::invalid_argument("Exercise already exists");
    }
    exercises.push_back(std::make_shared<Exercise>(name, caloriesBurnedPerHour, muscleGroup));
}

bool Calorix::updateFood(std::string foodName, double newCalories)
{
    requireAdmin();
    auto it = findFood(foodName);

    if (!it) {
        throw std::invalid_argument("Food not found");
    }
    it->setNewCalories(newCalories);
 
}

std::shared_ptr<User> Calorix::findUser(const std::string& username) const
{
    auto it = std::find_if(users.begin(), users.end(), [&](const auto& user) {
        return user->getName() == username;
        });
    if (it == users.end()) {
        return nullptr;
    }
    return *it;
}

std::shared_ptr<Food> Calorix::findFood(const std::string& name)
{
    auto it = std::find_if(foods.begin(), foods.end(), [&](const auto& food) {
        return food->getName() == name;
        });
    if (it == foods.end()) {
        return nullptr;
    }
    return *it;
}

std::shared_ptr<Exercise> Calorix::findExercise(const std::string& name)
{
    auto it = std::find_if(exercises.begin(), exercises.end(), [&](const auto& exercise) {
        return exercise->getName() == name;
        });
    if (it == exercises.end()) {
        return nullptr;
    }
    return *it;
}

void Calorix::logFood(const std::string& foodName, double quantityGrams, const Date& date)
{
    requireTrainee();

    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    auto food = findFood(foodName);
    if (!food) {
        throw std::invalid_argument("Food does not exist");
    }
    FoodEntry entry(food, quantityGrams, date);
    trainee->logFood(entry);
}

void Calorix::logExercise(const std::string& exerciseName, double durationMinutes, const Date& date)
{
    requireTrainee();
    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    auto exercise = findExercise(exerciseName);
    if (!exercise) {
        throw std::invalid_argument("Exercise not exist");

    }

    ExerciseEntry entry(exercise, durationMinutes, date);
    trainee->logExercise(entry);
}

void Calorix::addToFavorites(const std::string& exerciseName)
{
    requireTrainee();
    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    auto exercise = findExercise(exerciseName);
    if (!exercise) {
        throw std::invalid_argument("Exercise not exist");

    }
    trainee->addToFavorites(exercise);
}

void Calorix::viewDailySummary() const
{
    requireTrainee();

    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    trainee->viewDailySummary();
}

void Calorix::viewProgress() const
{
    requireTrainee();

    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    trainee->viewProgress();
}

void Calorix::calculateBMI() const
{
    requireTrainee();

    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    std::cout << "BMI: " << trainee->calculateBMI() << std::endl;
}

void Calorix::calculateBMR() const
{
    requireTrainee();

    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    std::cout << "BMR: " << trainee->calculateBMR() << std::endl;
}

void Calorix::viewFavorites() const
{
    requireTrainee();

    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    trainee->viewFavorites();
}
void Calorix::generateWorkoutPlan(int durationMinutes) const
{
    requireTrainee();

    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    trainee->generateWorkoutPlan(exercises, durationMinutes);
}

void Calorix::help() const
{
    requireLogin();
    currentUser->help();
}

void Calorix::end()
{
    std::cout << "Saving system data..." << std::endl;
}

