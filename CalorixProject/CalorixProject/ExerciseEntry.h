#pragma once
#include "Exercise.h"
#include "Date.h"
class ExerciseEntry {
	int entryId;
	static int idCounter;
	std::shared_ptr<Exercise> exercise;
	double durationMinutes;
	Date date;
public:
	ExerciseEntry(std::shared_ptr<Exercise> exercise, double duration);

	double getDuration()const;
	std::shared_ptr<Exercise> getExercise()const;
};