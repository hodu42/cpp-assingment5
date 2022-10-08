#pragma once
#include <iostream>

using namespace std;

class Day {
public:
	Day();
	Day(const int, const int, const int);
	const int getYear() const;
	const int getMonth() const;
	const int getDay() const;
	const Day operator ++();
	const Day operator --();
	const Day operator +(const int) const;
	const Day operator -(const int) const;
private:
	int year;
	int month;
	int day;
};
ostream& operator <<(ostream& outputStream, const Day& day);
bool isValidDate(const int, const int, const int);
bool isLeapYear(const int);