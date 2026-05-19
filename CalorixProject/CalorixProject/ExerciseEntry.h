#pragma once
#include "Exercise.h"
#include "Date.h"
class ExerciseEntry {
	int entryId;
	static int idCounter;
	Exercise& exercise;
	double durationMinutes;
	Date date;
public:
	ExerciseEntry(Exercise& exercise, double duration);
};