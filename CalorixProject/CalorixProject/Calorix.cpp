#include "Calorix.h"
#include <iostream>
#include "UserFactory.h"
#include "Admin.h"
#include <memory>
#include "Trainee.h"
#include <algorithm>
#include <fstream>
#include "EnumHelper.h"
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



void Calorix::registerUser(const std::string& username, const std::string& password, int age, double weight, double height,const Gender& gender)
{
    if (currentUser != nullptr) {
        throw std::runtime_error("You are already logged in");
    }
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
        throw std::runtime_error("You are already logged in");
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
    if (username == currentUser->getName()) {
        throw std::invalid_argument("Cannot block yourself");
    }
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

void Calorix::updateFood(std::string foodName, double newCalories)
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

void Calorix::setGoals(GoalType goalType, double targetValue, const Date& startDate, const Date& deadline) 
{
    requireTrainee();

    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);
    trainee->setGoals(goalType, targetValue, startDate, deadline);
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

void Calorix::viewProgress()
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

void Calorix::calculateTargetCalories() const
{
    requireTrainee();

    auto trainee = std::dynamic_pointer_cast<Trainee>(currentUser);

    std::cout << "Target calories: " << trainee->calculateTargetCalories() << std::endl;
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

bool Calorix::isLoggedIn() const
{
    return currentUser!=nullptr;
}

bool Calorix::isCurrentUserAdmin() const
{
    return std::dynamic_pointer_cast<Admin>(currentUser)!=nullptr;
}

bool Calorix::isCurrentUserTrainee() const
{
    return std::dynamic_pointer_cast<Trainee>(currentUser)!=nullptr;
}

void Calorix::loadFromFile(const std::string& file)
{
    users.clear();
    foods.clear();
    exercises.clear();
    currentUser = nullptr;
    std::ifstream in(file);
    if (!in) {
        users.push_back(
            UserFactory::createAdmin(
                "admin",
                "admin123",
                UserProfile(30, 80, 180, Gender::Male)
            )
        );

        return;
    }
    std::string type;
    while (in >> type) {
        if (type == "USER") {
            std::string username, password;
            int age;
            double weight, height;
            std::string genderText;
            in >> username >> password >> age >> weight >> height >> genderText;

            if (!isUsernameTaken(username)) {
                Gender gender = EnumHelper::stringToGender(genderText);
                UserProfile profile(age, weight, height, gender);
                users.push_back(UserFactory::createTrainee(username, password, profile));
            }
        }
        else if (type == "ADMIN") {
            std::string username, password;
            int age;
            double weight, height;
            std::string genderText;
            in >> username >> password >> age >> weight >> height >> genderText;

            if (!isUsernameTaken(username)) {
                Gender gender = EnumHelper::stringToGender(genderText);
                UserProfile profile(age, weight, height, gender);
                users.push_back(UserFactory::createAdmin(username, password, profile));
            }
        }
        else if (type == "FOOD") {
            std::string name;
            double calories, protein, carbs, fat;
            in >> name >> calories >> protein >> carbs >> fat;

            if (!findFood(name)) {
                foods.push_back(std::make_shared<Food>(name, calories, protein, carbs, fat));
            }
        }
        else if (type == "EXERCISE") {
            std::string name;
            double caloriesBurned;
            std::string muscleGroupText;
            in >> name >> caloriesBurned >> muscleGroupText;
            
            if (!findExercise(name)) {
                MuscleGroup muscleGroup = EnumHelper::stringToMuscleGroup(muscleGroupText);
                exercises.push_back(std::make_shared<Exercise>(name, caloriesBurned, muscleGroup));
            }
        }
        else if (type == "FOOD_ENTRY")
        {
            std::string username, foodName;
            double quantity;
            int d, m, y;

            in >> username >> foodName >> quantity >> d >> m >> y;

            auto user = findUser(username);
            auto trainee = std::dynamic_pointer_cast<Trainee>(user);
            auto food = findFood(foodName);

            if (trainee && food)
            {
                trainee->logFood(FoodEntry(food, quantity, Date(d, m, y)));
            }
        }
        else if (type == "EXERCISE_ENTRY")
        {
            std::string username, exerciseName;
            double duration;
            int d, m, y;

            in >> username >> exerciseName >> duration >> d >> m >> y;

            auto user = findUser(username);
            auto trainee = std::dynamic_pointer_cast<Trainee>(user);
            auto exercise = findExercise(exerciseName);

            if (trainee && exercise)
            {
                trainee->logExercise(ExerciseEntry(exercise, duration, Date(d, m, y)));
            }
        }
        else if (type == "FAVORITE")
        {
            std::string username, exerciseName;

            in >> username >> exerciseName;
 
            auto user = findUser(username);
            auto trainee = std::dynamic_pointer_cast<Trainee>(user);
            auto exercise = findExercise(exerciseName);

            if (trainee && exercise)
            {
                trainee->addToFavorites(exercise);
            }
        }
        else if (type == "GOAL")
        {
            std::string username, goalText;
            double target;

            int sd, sm, sy;
            int ed, em, ey;

            in >> username
                >> goalText
                >> target
                >> sd >> sm >> sy
                >> ed >> em >> ey;

            auto user = findUser(username);
            auto trainee = std::dynamic_pointer_cast<Trainee>(user);

            if (trainee)
            {
                trainee->setGoals(EnumHelper::stringToGoalType(goalText), target, Date(sd, sm, sy), Date(ed, em, ey));
            }
        }
    }
}

void Calorix::saveToFile(const std::string& file)
{
    std::ofstream out(file);
    if (!out) {
        throw std::runtime_error("Cannot be open");
    }

    for (const auto& user : users) {
        if (user->isAdmin()) {
            out << "ADMIN ";
        }
        else {
            out << "USER ";
        }
        const UserProfile& profile = user->getProfile();
        out << user->getName()<<" "<<user->getPassword()<<" "<<profile.getAge()<<" "
            <<profile.getWeight()<<" "<< profile.getHeight()<<" "<<EnumHelper::genderToString(profile.getGender())<<"\n";
    }

    for (const auto& food : foods) {
        out << "FOOD " <<food->getName()<<" " << food->getCalories() << " " << food->getProtein() << " " << food->getCarbs() << " " << food->getFat() << "\n";
    }
    for (const auto& exercise : exercises) {
        out << "EXERCISE " << exercise->getName() << " " << exercise->getCaloriesBurned() << " " << EnumHelper::muscleGroupToString(exercise->getMuscleGroup()) << "\n";
    }
    for (const auto& user : users) {
        auto trainee = std::dynamic_pointer_cast<Trainee>(user);
        if (!trainee) {
            continue;
        }
        for (const auto& food : trainee->getFoods()) {
            out << "FOOD_ENTRY " << user->getName() << " " <<
                food.getFood()->getName() << " " << food.getQuantityGrams() << " " <<
                food.getDate().getDay() << " " << food.getDate().getMonth() << " " << food.getDate().getYear() << "\n";
        }
        for (const auto& exercise : trainee->getExercises()) {
            out << "EXERCISE_ENTRY " << user->getName() << " " <<
                exercise.getExercise()->getName() << " " << exercise.getDuration() << " " <<
                exercise.getDate().getDay() << " " << exercise.getDate().getMonth() << " " << exercise.getDate().getYear() << "\n";
        }

        for (const auto& favorite : trainee->getFavorites()) {
            out << "FAVORITE" << " " << user->getName() << " "
                << favorite->getName() << "\n";
        }
        for (const auto& goal : trainee->getGoals()) {
            out << "GOAL " << user->getName() << " " <<
                EnumHelper::goalTypeToString(goal.getGoalType()) << " " << goal.getTargetValue() << " " <<
                goal.getStartDate().getDay() << " " << goal.getStartDate().getMonth() << " " << goal.getStartDate().getYear() << " " <<
                goal.getEndDate().getDay() << " " << goal.getEndDate().getMonth() << " " << goal.getEndDate().getYear()<<"\n";
        }
    }
}

