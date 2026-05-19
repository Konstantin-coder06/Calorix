#pragma once
class Date {
	int day;
	int month;
	int year;
public:
	Date(int day, int month, int year);
	Date() = default;
	~Date() = default;
	bool isValidDate(int day, int month, int year);
};