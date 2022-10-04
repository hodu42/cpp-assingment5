#pragma once
#include <iostream>

using namespace std;

class Day {
public:
	Day();
	const Day operator ++();
	const Day operator --();
	const Day operator +(const int);
	const Day operator -(const int);
private:
	int year;
	int month;
	int day;
	void setDateFormat();
	void initializeDays();
	static int leapDay[13];
	static int normalDay[13];
};