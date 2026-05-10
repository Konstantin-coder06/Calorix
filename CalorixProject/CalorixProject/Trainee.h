#pragma once
#include "User.h"
#include <vector>
#include "GoalType.h"
#include "FoodEntry.h"
#include "ExerciseEntry.h"
#include "FitnessGoal.h"

class Trainee : public User
{
	std::vector<FoodEntry> foodDiary;
	std::vector<ExerciseEntry> exerciseDiary;
	FitnessGoal goals;
	std::vector<Exercise> favoriteExercises;
public:
	void setGoals(GoalType goalType, int targetValue, std::string deadline);
	void logFood(Food foodName, double quantityGrams);
	void logExercise(ExerciseEntry exerciseName, double durationMinutes);
	void viewDailySummery();
	void viewProgress();
	double calculateBMI();
	double calculateBMR();
	void generateWorkoutPlan(double durationMinutes);
	void addToFavorites(Exercise exerciseName);
	void viewFavorites();
};