#pragma once
#include <vector>
#include "User.h"
#include "Food.h"
#include "Exercise.h"
#include <memory>
#include "Date.h"
#include "GoalType.h"
class Calorix {
	char* name;

	std::vector<std::shared_ptr<User>> users;
	std::vector<std::shared_ptr<Food>> foods;
	std::vector<std::shared_ptr<Exercise>> exercises;

	std::shared_ptr<User> currentUser;
	static Calorix* instance;

	

	void requireLogin()const;
	void requireAdmin()const;
	void requireTrainee()const;

	std::shared_ptr<User>findUser(const std::string& username)const;

public:
	static Calorix& getInstance();

	Calorix();
	void registerUser(std::string username, std::string password, int age, double weight, double height,const Gender& gender);
	bool isUsernameTaken(const std::string& name);
	void login(std::string username, std::string password);
	void logout();
    void blockUser(std::string username);

	void addFood(std::string name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g);
	void addExercise(std::string name, double caloriesBurnedPerHour, MuscleGroup muscleGroup);
	void updateFood(std::string foodName, double newCalories);

	std::shared_ptr<Food> findFood(const std::string& name);
	std::shared_ptr<Exercise> findExercise(const std::string& name);

	void setGoals(GoalType goalType, double targetValue, const Date& startDate, const Date& deadline);

	void logFood(const std::string& foodName, double quantityGrams, const Date& date);
	void logExercise(const std::string& exerciseName, double durationMinutes, const Date& date);

	void addToFavorites(const std::string& exerciseName);

	void viewDailySummary() const;
	void viewProgress();

	void calculateBMI() const;
	void calculateBMR() const;
	
	void viewFavorites() const;
	void generateWorkoutPlan(int durationMinutes) const;
	
	void help() const;
	void end();

	bool isLoggedIn() const;
	bool isCurrentUserAdmin() const;
	bool isCurrentUserTrainee() const;

	void loadFromFile(const std::string& file);
	void saveToFile(const std::string& file);
};