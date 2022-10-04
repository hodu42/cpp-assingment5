#include "Day.h"
#include "Common.h"

Common common;

Day::Day() {
	year = 2022;
	month = 10;
	day = 3;
}
Day::Day(int inputYear, int inputMonth, int inputDay) {
	year = inputYear;
	month = inputMonth;
	day = inputDay;
}
const int Day::getYear() const {
	return year;
}
const int Day::getMonth() const {
	return month;
}
const int Day::getDay() const {
	return day;
}
void Day::setYear(int inputYear) {

}
void Day::setMonth(int inputMonth) {

}
void Day::setDay(int inputMonth) {

}
void Day::initializeDays() {
	int leap[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int normal[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < 12; i++) {
		leapDay[i] = leap[i];
		normalDay[i] = normal[i];
	}
}
void Day::setDateFormat() {
	
}
const Day Day::operator ++() const {
	int resultYear = year;
	int resultMonth = month;
	int resultDay = day;
	resultDay++;
	if (common.isLeapYear(resultYear)) {
		if (resultDay > leapDay[resultMonth]) {
			resultDay -= leapDay[resultMonth];
			resultMonth++;
			if (resultMonth > 12) {
				resultMonth = 1;
			}
		}
	}
	else {
		if (resultDay > normalDay[resultMonth]) {
			resultDay -= normalDay[resultMonth];
			resultMonth++;
			if (resultMonth > 12) {
				resultMonth = 1;
			}
		}
	}
	return Day(resultYear, resultMonth, resultDay);
}
const Day Day::operator --() const {
	int resultYear = year;
	int resultMonth = month;
	int resultDay = day;
	resultDay--;
	if (common.isLeapYear(resultYear)) {
		if (resultDay < 1) {
			resultMonth--;
			if (resultMonth < 1) {
				resultYear--;
				resultMonth = 12;
				resultDay = normalDay[resultMonth];
			}
			else {
				resultDay = leapDay[resultMonth];
			}
		}
	}
	else {
		if (resultDay < 1) {
			resultMonth--;
			if (resultMonth < 1) {
				resultYear--;
				resultMonth = 12;
				if (common.isLeapYear(resultYear)) {
					resultDay = leapDay[resultMonth];
				}
				else {
					resultDay = normalDay[resultMonth];
				}
			}
			else {
				resultDay = leapDay[resultMonth];
			}
		}
	}
	return Day(resultYear, resultMonth, resultDay);
}
const Day Day::operator +(int inputDay) const {
	int resultYear = year;
	int resultMonth = month;
	int resultDay;
	inputDay -= 1;
	while (inputDay >= 365) {
		if (!common.isLeapYear(resultYear + 1)) {
			if (inputDay >= 365) {
				inputDay -= 365;
				resultYear++;
			}
		}
		else {
			if (inputDay >= 366) {
				inputDay -= 366;
				resultYear++;
			}
		}
	}
	resultDay = day + inputDay;
	
	while (resultDay / 10 != 0) {
		if (common.isLeapYear(resultYear)) {
			if (resultDay > leapDay[resultMonth]) {
				resultDay -= leapDay[resultMonth];
				resultMonth++;
				if (resultMonth > 12) {
					resultYear++;
					resultMonth = 1;
				}
			}
		}
		else {
			if (resultDay > normalDay[resultMonth]) {
				resultDay -= normalDay[resultMonth];
				resultMonth++;
				if (resultMonth > 12) {
					resultYear++;
					resultMonth = 1;
				}
			}
		}
	}
	return Day(resultYear, resultMonth, resultDay);
}
const Day Day::operator -(int inputDay) const {
	int resultYear = year;
	int resultMonth = month;
	int resultDay;
	while (inputDay <= -365) {
		if (!common.isLeapYear(resultYear - 1)) {
			if (inputDay <= -365) {
				inputDay += 365;
				resultYear--;
			}
		}
		else {
			if (inputDay <= -366) {
				inputDay += -366;
				resultYear--;
			}
		}
	}
	resultDay = day + inputDay;

	while (resultDay < 0) {
		if (common.isLeapYear(resultYear)) {
			resultDay += leapDay[resultMonth];
			resultMonth--;
			if (resultMonth < 1) {
				resultYear--;
				resultMonth = 12;
			}
		}
		else {
			while (resultDay > normalDay[resultMonth]) {
				resultDay += normalDay[resultMonth];
				resultMonth--;
				if (resultMonth < 1) {
					resultYear--;
					resultMonth = 12;
				}
			}
		}
	}
	return Day(resultYear, resultMonth, resultDay);
}
ostream& operator <<(ostream& outputStream, const Day& day) {
	return outputStream << day.getYear() << "/" << day.getMonth() << "/" << day.getDay();
}