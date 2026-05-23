#include "Trainee.h"
#include <iostream>

Trainee::Trainee(std::vector<FoodEntry> foodDiary, std::vector<ExerciseEntry> exerciseDiary, std::vector<FitnessGoal> goals, std::vector<Exercise> favoriteExercises)
{
	this->foodDiary = foodDiary;
	this->exerciseDiary = exerciseDiary;
	this->goals = goals;
	this->favoriteExercises = favoriteExercises;
}

void Trainee::setGoals(GoalType goalType, int targetValue, Date deadline)
{ 
	goals.push_back(FitnessGoal(goalType, targetValue, deadline));
}

void Trainee::logFood(Food foodName, double quantityGrams)
{
	foodDiary.push_back(FoodEntry(foodName, quantityGrams));
}

void Trainee::logExercise(Exercise exerciseName, double durationMinutes)
{
	exerciseDiary.push_back(ExerciseEntry(exerciseName, durationMinutes));
}

void Trainee::viewDailySummery()
{
	std::cout << "Your Daily Summery:" << std::endl;
	double sumOfCalories = 0;
	double sumOfProtein = 0;
	double sumOfCarbs = 0;
	double sumOfFat = 0;

	for (auto it : foodDiary) {
		sumOfCalories += it.getFood().getCalories() * it.getQuantityGrams() / 100;
		sumOfProtein += it.getFood().getProtein() * it.getQuantityGrams() / 100;
		sumOfCarbs += it.getFood().getCarbs() * it.getQuantityGrams() / 100;
		sumOfFat += it.getFood().getFat() * it.getQuantityGrams() / 100;
	}

	std::cout << "Calories: " << sumOfCalories << std::endl;
	std::cout << "Protein: " << sumOfProtein << std::endl;
	std::cout << "Carbs: " << sumOfCarbs << std::endl;
	std::cout << "Fat: " << sumOfFat << std::endl;
}

void Trainee::viewProgress()
{
	UserProfile userProfile = getProfile();
	double currentWeight = userProfile.getWeight();
	double deadline = 0;
	for (auto it : goals) {
		if (it.getIsAchieved() == false) {
			deadline = it.getTargetValue();
		}
	}
	if (deadline != 0) {
		double diff = deadline - currentWeight;
		std::cout << "You need " << diff << " kilos to complete your goal"<< std::endl;
	}
	else {
		std::cout << "You are completed all goals" << std::endl;

	}
}
double myPow(double number) {
	return number * number;
}
void Trainee::calculateBMI()
{
	UserProfile userProfile = getProfile();
	double weight = userProfile.getWeight();
	double height = userProfile.getHeight();

	double bmi = weight / (myPow(height / 100));

    std::cout<<"Your BMI is:"<<bmi<<std::endl;
}

void Trainee::calculateBMR()
{
	UserProfile userProfile = getProfile();

	double weight = userProfile.getWeight();
	double height = userProfile.getHeight();
	double age = userProfile.getAge();
	double bmr = 0;

	if (userProfile.getGender() == true) {

		bmr = 10 * weight + 6.25 * height - 5 * age + 5;
	}
	else {
	    bmr = 10 * weight + 6.25 * height - 5 * age - 161;
	}
	std::cout << "Your BMR is:" << bmr << std::endl;

}
