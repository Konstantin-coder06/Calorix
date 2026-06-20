#pragma once
class Date {
	int day;
	int month;
	int year;
public:
	Date(int day, int month, int year);
	Date();
	~Date() = default;
	static bool isValidDate(int day, int month, int year);
	static Date getToday();
	static void IsCorrectStartEndDate(const Date& startDate, const Date& endDate);

	int getDay()const;
	int getMonth()const;
	int getYear()const;
};