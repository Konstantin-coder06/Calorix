#pragma once
#include "Exercise.h"
#include "Date.h"
#include <memory>
class ExerciseEntry {
	int entryId;
	static int idCounter;
	std::shared_ptr<Exercise> exercise;
	double durationMinutes;
	Date date;
public:
	ExerciseEntry(std::shared_ptr<Exercise> exercise, double durationMinutes, const Date& date);

	double getDuration()const;
	std::shared_ptr<Exercise> getExercise()const;
	Date getDate()const;

	double calculateBurnedCalories() const;


};