#pragma once
#include <iostream>

using namespace std;

class Day {
public:
	Day();
	Day(int, int, int);
	const int getYear() const;
	const int getMonth() const;
	const int getDay() const;
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	const Day operator ++();
	const Day operator --();
	const Day operator +(int) const;
	const Day operator -(int) const;
private:
	int year;
	int month;
	int day;
};
ostream& operator <<(ostream& outputStream, const Day& day);