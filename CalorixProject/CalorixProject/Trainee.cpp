#include "Trainee.h"

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

}
