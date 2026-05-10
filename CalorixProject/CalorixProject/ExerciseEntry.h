#pragma once
#include "Exercise.h"
class ExerciseEntry {
	int entryId;
	static int idCounter;
	Exercise& exercise;
	double durationMinutes;
	std::string date;
};