#include "Trainee.h"
#include <iostream>
#include "User.h"

Trainee::Trainee(std::string username, std::string password, UserProfile profile,
	std::vector<std::shared_ptr<FoodEntry>> foodDiary, std::vector<std::shared_ptr<ExerciseEntry>> exerciseDiary, std::vector<FitnessGoal> goals, std::vector<std::shared_ptr<Exercise>> favoriteExercises)
	:User(username, password, profile),
	foodDiary(std::move(foodDiary)),
	exerciseDiary(std::move(exerciseDiary)),
	goals(std::move(goals)),
	favoriteExercises(std::move(favoriteExercises))
{

}

void Trainee::setGoals(GoalType goalType, int targetValue, Date deadline)
{ 
	goals.push_back(FitnessGoal(goalType, targetValue, deadline));
}

void Trainee::logFood(std::shared_ptr<Food> foodName, double quantityGrams)
{
	foodDiary.push_back(std::make_shared<FoodEntry>(foodName, quantityGrams));
}

void Trainee::logExercise(std::shared_ptr<Exercise> exerciseName, double durationMinutes)
{
	exerciseDiary.push_back(std::make_shared<ExerciseEntry>(exerciseName, durationMinutes));
}

void Trainee::viewDailySummary()const
{
	std::cout << "Your Daily Summary:" << std::endl;
	double sumOfCalories = 0;
	double sumOfProtein = 0;
	double sumOfCarbs = 0;
	double sumOfFat = 0;

	for (const auto& it : foodDiary) {
		sumOfCalories += it->getFood()->getCalories() * it->getQuantityGrams() / 100;
		sumOfProtein += it->getFood()->getProtein() * it->getQuantityGrams() / 100;
		sumOfCarbs += it->getFood()->getCarbs() * it->getQuantityGrams() / 100;
		sumOfFat += it->getFood()->getFat() * it->getQuantityGrams() / 100;
	}

	std::cout << "Calories: " << sumOfCalories << std::endl;
	std::cout << "Protein: " << sumOfProtein << std::endl;
	std::cout << "Carbs: " << sumOfCarbs << std::endl;
	std::cout << "Fat: " << sumOfFat << std::endl;
}

void Trainee::viewProgress()const
{
	UserProfile userProfile = getProfile();
	double currentWeight = userProfile.getWeight();
	double deadline = 0;
	for (const auto& it : goals) {
		if (!it.getIsAchieved()) {
			deadline = it.getTargetValue();
		}
	}
	if (deadline != 0) {
		double diff = deadline - currentWeight;
		throw std::invalid_argument("You need " + std::to_string(diff) + " kilos to complete your goal");
	}
	else {
		std::cout << "You are completed all goals" << std::endl;

	}
}
double myPow(double number) {
	return number * number;
}
void Trainee::calculateBMI() const
{
	UserProfile userProfile = getProfile();
	double weight = userProfile.getWeight();
	double height = userProfile.getHeight();

	double bmi = weight / (myPow(height / 100));

    std::cout<<"Your BMI is:"<<bmi<<std::endl;
}

void Trainee::calculateBMR() const
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

void Trainee::generateWorkoutPlan(double durationMinutes)
{
	int n = favoriteExercises.size();
	int capacity = static_cast<int>(durationMinutes);
	std::vector<std::vector<double>> dp(n + 1, std::vector<double>(capacity + 1, 0));

	for (int i = 1; i <= n;i++) {
		double duration = exerciseDiary[i - 1]->getDuration();

		double cal = favoriteExercises[i - 1]->getCaloriesBurned()*(duration/60.0);
	
		for (int j = 0;j <= capacity;j++) {
			if (duration <= j) {
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - static_cast<int>(duration)] + cal);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
}

void Trainee::addToFavorites(std::shared_ptr<Exercise> exerciseName)
{
	favoriteExercises.push_back(exerciseName);
}

void Trainee::viewFavorites()const
{
	std::cout << "Your favourite exercises:" << std::endl;
	for (const auto& it : favoriteExercises) {
		std::cout << "Exercise: " << it->getName() << std::endl;
	}
}
