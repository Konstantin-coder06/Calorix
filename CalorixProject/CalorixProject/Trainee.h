#pragma once
#include "User.h"
#include <vector>
#include "GoalType.h"
#include "FoodEntry.h"
#include "ExerciseEntry.h"
#include "FitnessGoal.h"
#include "Date.h"
#include "Food.h"

class Trainee : public User
{
	std::vector<std::shared_ptr<FoodEntry>> foodDiary;
	std::vector<std::shared_ptr<ExerciseEntry>> exerciseDiary;
	std::vector<FitnessGoal> goals;
	std::vector<std::shared_ptr<Exercise>> favoriteExercises;
public:
	Trainee(std::string username, std::string password, UserProfile profile,
		std::vector<std::shared_ptr<FoodEntry>> foodDiary, std::vector<std::shared_ptr<ExerciseEntry>> exerciseDiary, std::vector<FitnessGoal> goals, std::vector<std::shared_ptr<Exercise>> favoriteExercises);
	Trainee() = default;
	void setGoals(GoalType goalType, int targetValue, Date deadline);
	void logFood(std::shared_ptr<Food> foodName, double quantityGrams);
	void logExercise(std::shared_ptr<Exercise> exerciseName, double durationMinutes);
	void viewDailySummary() const;
	void viewProgress() const;
	void calculateBMI() const;
	void calculateBMR() const;
	void generateWorkoutPlan(double durationMinutes);
	void addToFavorites(std::shared_ptr<Exercise> exerciseName);
	void viewFavorites() const;
};