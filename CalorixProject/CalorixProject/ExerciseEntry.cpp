#include "ExerciseEntry.h"
#include <memory>
#include "Date.h"
#include <stdexcept>
ExerciseEntry::ExerciseEntry(
    std::shared_ptr<Exercise> exercise,
    double durationMinutes,
    const Date& date)
    :
    exercise(exercise),
   
    date(date)
{
    if (durationMinutes <= 0|| durationMinutes>120) {
        throw std::invalid_argument("Duration must be between the interval [1,120]");
    }
    this->durationMinutes = durationMinutes;
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

