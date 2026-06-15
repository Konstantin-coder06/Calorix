#include "Date.h"
#include <stdexcept>
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
