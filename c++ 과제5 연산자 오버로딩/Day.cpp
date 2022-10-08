#include "Day.h"
#include <iomanip>

using namespace std;

static const int MAX_MONTH = 12;
static const int MAX_DAYS_OF_MONTHS[MAX_MONTH + 1] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Day::Day() {
	year = 2022;
	month = 9;
	day = 29;
}

Day::Day(const int inputYear, const int inputMonth, const int inputDay) {
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

bool isLeapYear(const int inputYear) {
	return ((inputYear % 4 == 0 && inputYear % 100 != 0) || inputYear % 400 == 0);
}

bool isValidDate(const int inputYear, const int inputMonth, const int inputDay) {

	if (1 <= inputMonth && inputMonth <= 12) {
		if (1 <= inputDay && (inputDay <= MAX_DAYS_OF_MONTHS[inputMonth] + (inputMonth == 2 && isLeapYear(inputYear)))) {
			return 1;
		}
		else {
			cout << "*** Error!!" << endl;
			return 0;
		}
	}
	else {
		cout << "*** Error!!" << endl;
		return 0;
	}

}

const Day Day::operator ++() {

	day++;

	if (day > MAX_DAYS_OF_MONTHS[month] + (month == 2 && isLeapYear(year))) {
		day -= MAX_DAYS_OF_MONTHS[month] + (month == 2 && isLeapYear(year));
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
		day = MAX_DAYS_OF_MONTHS[month] + (month == 2 && isLeapYear(year));
	}
	
	return Day(year, month, day);
}

const Day Day::operator +(const int inputDay) const {

	int resultYear = year;
	int resultMonth = month;
	int resultDay = day + (inputDay - 1);
	int max_day_of_year;

	while (resultDay >= 365) {

		max_day_of_year = 365;

		if (isLeapYear(resultYear)) {
			if (resultMonth < 3) {
				max_day_of_year = 366;
			}
		}
		else if (resultMonth > 2) {
			if (isLeapYear(resultYear + 1)) {
				max_day_of_year = 366;
			}
		}

		resultDay -= max_day_of_year;
		resultYear++;
	}

	while (resultDay > MAX_DAYS_OF_MONTHS[resultMonth] + (resultMonth == 2 && isLeapYear(resultYear))) {
		resultDay -= MAX_DAYS_OF_MONTHS[resultMonth] + (resultMonth == 2 && isLeapYear(resultYear));
		resultMonth++;
		if (resultMonth > 12) {
			resultYear++;
			resultMonth = 1;
		}
	}

	if (resultDay <= 0) {
		resultMonth--;
		if (resultMonth < 1) {
			resultYear--;
			resultMonth = 12;
		}
		resultDay = MAX_DAYS_OF_MONTHS[resultMonth] + (resultMonth == 2 && isLeapYear(resultYear));
	}

	return Day(resultYear, resultMonth, resultDay);
}

const Day Day::operator -(const int inputDay) const {

	int resultYear = year;
	int resultMonth = month;
	int resultDay = day - inputDay;
	int max_day_of_year;

	while (resultDay <= -365) {

		max_day_of_year = 365;

		if (isLeapYear(resultYear)) {
			if (resultMonth > 2) {
				max_day_of_year = 366;
			}
		}
		else if (resultMonth <= 2) {
			if (isLeapYear(resultYear - 1)) {
				max_day_of_year = 366;
			}
		}

		resultDay += max_day_of_year;
		resultYear--;
	}
	
	while (resultDay < 0) {
		resultDay += MAX_DAYS_OF_MONTHS[resultMonth - 1] + (resultMonth - 1 == 2 && isLeapYear(resultYear));
		resultMonth--;
		if (resultMonth < 1) {
			resultYear--;
			resultMonth = 12;
		}
	}

	if (resultDay <= 0) {
		resultMonth--;
		if (resultMonth < 1) {
			resultYear--;
			resultMonth = 12;
		}
		resultDay = MAX_DAYS_OF_MONTHS[resultMonth] + (resultMonth == 2 && isLeapYear(resultYear));
	}

	return Day(resultYear, resultMonth, resultDay);
}

ostream& operator <<(ostream& outputStream, const Day& day) {
	outputStream << day.getYear() << "/";
	outputStream << setfill('0') << setw(2) << right << day.getMonth() << "/";
	return outputStream << setfill('0') << setw(2) << right << day.getDay();;
}