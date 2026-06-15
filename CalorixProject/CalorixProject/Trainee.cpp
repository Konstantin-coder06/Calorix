#include "Trainee.h"
#include <iostream>
#include "User.h"
#include "GoalStrategy.h"
#include "BulkingStrategy.h"
#include "WeightLossStrategy.h"
#include "MaitenanceStrategy.h"
Trainee::Trainee(std::string username, std::string password, UserProfile profile)
	:User(username, password, profile)
{
}

void Trainee::setGoals(GoalType goalType, int targetValue, Date startDate, Date deadline)
{ 
	if (targetValue <= 0) {
		throw std::invalid_argument("Target must be positive");
	}
	goals.push_back(FitnessGoal(goalType, targetValue, startDate, deadline));
}

void Trainee::logFood(const FoodEntry& entry)
{
	foodDiary.push_back(entry);
}

void Trainee::logExercise(const ExerciseEntry& entry)
{
	exerciseDiary.push_back(entry);
}

void Trainee::viewDailySummary()const
{
	std::cout << "Your Daily Summary:" << std::endl;
	double sumOfCalories = 0;
	double sumOfProtein = 0;
	double sumOfCarbs = 0;
	double sumOfFat = 0;
	double totalCaloriesOut = 0;
	for (const auto& it : foodDiary) {
		sumOfCalories += it.calculateCalories();
		sumOfProtein += it.getFood()->getProtein() * it.getQuantityGrams() / 100;
		sumOfCarbs += it.getFood()->getCarbs() * it.getQuantityGrams() / 100;
		sumOfFat += it.getFood()->getFat() * it.getQuantityGrams() / 100;
	}
	for (const auto& entry : exerciseDiary)
	{
		totalCaloriesOut += entry.calculateBurnedCalories();
	}
	std::cout << "Total Calories: " << sumOfCalories << std::endl;
	std::cout << "Calories burned:" << totalCaloriesOut << std::endl;
	std::cout << "Net balance: " << sumOfCalories - totalCaloriesOut << std::endl;

	std::cout << "Protein: " << sumOfProtein << std::endl;
	std::cout << "Carbs: " << sumOfCarbs << std::endl;
	std::cout << "Fat: " << sumOfFat << std::endl;
}


void Trainee::viewProgress()const
{
	if (goals.empty()) {
		std::cout << "No goals yet" << std::endl;
		return;
	}
	const FitnessGoal& goal = goals.back();
	if (goal.getGoalType() == GoalType::WeightLoss ||
		goal.getGoalType() == GoalType::Bulking) {
		double diff = goal.getTargetValue() - getProfile().getWeight();
		if (diff > 0)
		{
			std::cout << "You need " << diff << " kg more to reach your goal." << std::endl;
		}
		else if (diff < 0)
		{
			std::cout << "You need to lose " << -diff << " kg to reach your goal." << std::endl;
		}
		else
		{
			std::cout << "Goal achieved." << std::endl;
		}
	}
	else
	{
		std::cout << "Maintenance goal active." << std::endl;
	}
}


double Trainee::calculateBMI() const
{
	UserProfile userProfile = getProfile();
	double weight = userProfile.getWeight();
	double height = userProfile.getHeight()/100;
	if (height <= 0)
	{
		throw std::invalid_argument("Invalid height.");
	}
	return userProfile.getWeight() / (height * height);
}

double Trainee::calculateBMR() const
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
	return bmr;

}

void Trainee::generateWorkoutPlan(
	const std::vector<std::shared_ptr<Exercise>>& exercises,
	double duration)
{
	if (duration <= 0)
	{
		throw std::invalid_argument("Duration must be positive.");
	}
	int n = exercises.size();
	int capacity = duration;

	const int exerciseDuration = 30;

	std::vector<std::vector<double>> dp(
		n + 1,
		std::vector<double>(capacity + 1, 0)
	);

	for (int i = 1; i <= n; i++)
	{
		double calories =
			exercises[i - 1]->getCaloriesBurned() * (exerciseDuration / 60.0);

		for (int j = 0; j <= capacity; j++)
		{
			if (exerciseDuration <= j)
			{
				dp[i][j] = std::max(
					dp[i - 1][j],
					dp[i - 1][j - exerciseDuration] + calories
				);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	std::cout << "Best calories burned: " << dp[n][capacity] << std::endl;

	int j = capacity;

	std::cout << "Workout plan:" << std::endl;

	for (int i = n; i >= 1; i--)
	{
		if (dp[i][j] != dp[i - 1][j])
		{
			std::cout << exercises[i - 1]->getName() << std::endl;
			j -= exerciseDuration;
		}
	}
}

void Trainee::addToFavorites(std::shared_ptr<Exercise> exerciseName)
{
	if (!exerciseName) {
		throw std::invalid_argument("Exercise cannot be without name");
	}
	favoriteExercises.push_back(exerciseName);
}

void Trainee::viewFavorites()const
{
	if (favoriteExercises.empty()) {
		std::cout << "No favorite exercises" << std::endl;
	}
	std::cout << "Your favourite exercises:" << std::endl;
	for (const auto& it : favoriteExercises) {
		std::cout << "Exercise: " << it->getName() << std::endl;
	}
}

bool Trainee::isAdmin() const
{
	return false;
}
void Trainee::help() const
{
	std::cout << "Trainee commands:" << std::endl;
	std::cout << "set-goals" << std::endl;
	std::cout << "log-food" << std::endl;
	std::cout << "log-exercise" << std::endl;
	std::cout << "view-daily-summary" << std::endl;
	std::cout << "view-progress" << std::endl;
	std::cout << "calculate-bmi" << std::endl;
	std::cout << "calculate-bmr" << std::endl;
	std::cout << "generate-workout-plan" << std::endl;
	std::cout << "add-to-favorites" << std::endl;
	std::cout << "view-favorites" << std::endl;
}
double Trainee::calculateTargetCalories() const
{
	if (goals.empty()) {
		return calculateBMR();
	}
	std::unique_ptr<GoalStrategy> strategy;
	switch (goals.back().getGoalType()) {
	case GoalType::Bulking:
		strategy = std::make_unique<BulkingStrategy>();
		break;
	case GoalType::WeightLoss:
		strategy = std::make_unique<WeightLossStrategy>();
		break;
	case GoalType::Maintenance:
		strategy = std::make_unique<MaitenanceStrategy>();
		break;
	}
	
	return strategy->calculateTargetCalories(getProfile());
}
