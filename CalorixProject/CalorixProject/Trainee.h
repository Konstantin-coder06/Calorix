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
	std::vector<FoodEntry> foodDiary;
	std::vector<ExerciseEntry> exerciseDiary;
	std::vector<FitnessGoal> goals;
	std::vector<Exercise> favoriteExercises;
public:
	Trainee(std::vector<FoodEntry> foodDiary, std::vector<ExerciseEntry> exerciseDiary, std::vector<FitnessGoal> goals, std::vector<Exercise> favoriteExercises);
	Trainee() = default;
	void setGoals(GoalType goalType, int targetValue, Date deadline);
	void logFood(Food foodName, double quantityGrams);
	void logExercise(Exercise exerciseName, double durationMinutes);
	void viewDailySummery();
	void viewProgress();
	void calculateBMI();
	void calculateBMR();
	void generateWorkoutPlan(double durationMinutes);
	void addToFavorites(Exercise exerciseName);
	void viewFavorites();
};