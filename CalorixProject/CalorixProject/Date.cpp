#include "Date.h"
#include <stdexcept>
#include <ctime>
Date::Date(int day, int month, int year)
{
	if (!isValidDate(day, month, year)) {
		throw std::invalid_argument("Invalid date");
	}
	this->day = day;
	this->month = month;
	this->year = year;
}

bool Date::isValidDate(int day, int month, int year)
{
	if (year < 1) return false;
	if (month < 1 || month > 12) return false;
	if (day < 1) return false;

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return day <= 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return day <= 30;
	case 2: {
		bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		return day <= (leap ? 29 : 28);
	}
	default:
		return false;
	}
}
Date Date::getToday()
{
	time_t now = time(nullptr);

	tm localTime;
	localtime_s(&localTime, &now);

	return Date(
		localTime.tm_mday,
		localTime.tm_mon + 1,
		localTime.tm_year + 1900
	);
}

void Date::IsCorrectStartEndDate(const Date& startDate, const Date& endDate)
{
	if (endDate.year < startDate.year) {
		throw std::invalid_argument("End year is smaller than start year");
	}
	if (endDate.year == startDate.year) {
		if (endDate.month < startDate.month) {
			throw std::invalid_argument("End month is smaller than start month");
		}
		else if (endDate.month == startDate.month) {
			if (endDate.day < startDate.day) {
				throw std::invalid_argument("End day is smaller than start day");
			}
		}
	}
}
