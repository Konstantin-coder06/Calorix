#include "ExerciseEntry.h"
#include <memory>

ExerciseEntry::ExerciseEntry(std::shared_ptr<Exercise> exercise, double duration)
	:exercise(exercise),
	durationMinutes(duration){}

double ExerciseEntry::getDuration() const
{
	return durationMinutes;
}

std::shared_ptr<Exercise> ExerciseEntry::getExercise() const
{
	return exercise;
}

