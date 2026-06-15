#include "ExerciseEntry.h"
#include <memory>
#include "Date.h"

ExerciseEntry::ExerciseEntry(
    std::shared_ptr<Exercise> exercise,
    double durationMinutes,
    const Date& date)
    :
    exercise(exercise),
    durationMinutes(durationMinutes),
    date(date)
{
}

double ExerciseEntry::getDuration() const
{
	return durationMinutes;
}

std::shared_ptr<Exercise> ExerciseEntry::getExercise() const
{
	return exercise;
}

double ExerciseEntry::calculateBurnedCalories() const
{
	if (!exercise) return 0.0;
	return exercise->getCaloriesBurned() * (durationMinutes / 60.0);
}

