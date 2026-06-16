#pragma once
#include "User.h"
#include <vector>
#include "GoalType.h"
#include "FoodEntry.h"
#include "ExerciseEntry.h"
#include "FitnessGoal.h"
#include "Date.h"
#include "UserProfile.h"
#include "Exercise.h"
#include <memory>

class Trainee : public User
{
	std::vector<FoodEntry> foodDiary;
	std::vector<ExerciseEntry> exerciseDiary;
	std::vector<FitnessGoal> goals;
	std::vector<std::shared_ptr<Exercise>> favoriteExercises;
public:
	Trainee(std::string username, std::string password, UserProfile profile);
		
	Trainee() = default;

	void setGoals(GoalType goalType, int targetValue,Date startDate, Date deadline);

	void logFood(const FoodEntry& entry);
	void logExercise(const ExerciseEntry& entry);

	void viewDailySummary() const;
	void viewProgress();
	void viewFavorites() const;

	double calculateBMI() const;
	double calculateBMR() const;

	void generateWorkoutPlan(const std::vector<std::shared_ptr<Exercise>>& exercises, double durationMinutes);

	void addToFavorites(std::shared_ptr<Exercise> exerciseName);
	
	bool isAdmin()const override;
	double calculateTargetCalories() const;
	void help()const override;

	std::vector<FoodEntry> getFoods()const;
	std::vector<ExerciseEntry>getExercises()const;
	std::vector<FitnessGoal>getGoals()const;
	std::vector<std::shared_ptr<Exercise>>getFavorites()const;
};