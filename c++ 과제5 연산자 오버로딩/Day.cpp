#include "Day.h"
#include "Common.h"
#include <iomanip>

Common common;

using namespace std;

const int MAX_MONTH = 12;
const int MAX_DAYS_OF_MONTHS[MAX_MONTH + 1] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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
	year = inputYear;
}
void Day::setMonth(int inputMonth) {
	month = inputMonth;
}
void Day::setDay(int inputDay) {
	day = inputDay;
}
const Day Day::operator ++() {
	day++;
	if (day > MAX_DAYS_OF_MONTHS[month] + (month == 2 && common.isLeapYear(year))) {
		day -= MAX_DAYS_OF_MONTHS[month] + (month == 2 && common.isLeapYear(year));
		month++;
	}
	if (month > 12) {
		year++;
		month = 1;
	}

	return Day(year, month, day);
}
const Day Day::operator --() {
	day--;
	if (day < 1) {
		month--;
		if (month < 1) {
			year--;
			month = 12;
		}
		day = MAX_DAYS_OF_MONTHS[month] + (month == 2 && common.isLeapYear(year));
	}
	
	return Day(year, month, day);
}
const Day Day::operator +(int inputDay) const {
	int resultYear = year;
	int resultMonth = month;
	int resultDay;
	inputDay -= 1;
	while (inputDay >= 365 + common.isLeapYear(resultYear + 1) ) {
		inputDay -= 365 + common.isLeapYear(resultYear + 1);
		resultYear++;
	}
	resultDay = day + inputDay;
	
	while (resultDay / 10 != 0) {
		if (resultDay > MAX_DAYS_OF_MONTHS[resultMonth] + (month == 2 && common.isLeapYear(resultYear))) {
			resultDay -= MAX_DAYS_OF_MONTHS[resultMonth] + (month == 2 && common.isLeapYear(resultYear));
			resultMonth++;
		}
		if (resultMonth > 12) {
			resultYear++;
			resultMonth = 1;
		}
	}
	return Day(resultYear, resultMonth, resultDay);
}
const Day Day::operator -(int inputDay) const {
	int resultYear = year;
	int resultMonth = month;
	int resultDay;
	while (-inputDay <= 365 + (month == 2 && common.isLeapYear(resultYear))) {
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
			/*resultDay += leapDay[resultMonth];*/
			resultMonth--;
			if (resultMonth < 1) {
				resultYear--;
				resultMonth = 12;
			}
		}
		else {
			while (resultDay > MAX_DAYS_OF_MONTHS[resultMonth]) {
				resultDay += MAX_DAYS_OF_MONTHS[resultMonth];
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
	outputStream << day.getYear() << "/";
	outputStream << setfill('0') << setw(2) << right << day.getMonth() << "/";
	return outputStream << setfill('0') << setw(2) << right << day.getDay();;
}