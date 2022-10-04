#include "Day.h"
#include "Common.h"

Common common;

Day::Day() {
	year = 2022;
	month = 10;
	day = 3;
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
const Day Day::operator ++() {
	if (common.isLeapYear(year)) {
		if (day > leapDay[month]) {
			day -= leapDay[month];
			month++;
			if (month > 12) {
				month = 1;
			}
		}
		else {
			day++;
		}
	}
	else {
		if (day > normalDay[month]) {
			day -= normalDay[month];
			month++;
			if (month > 12) {
				month = 1;
			}
		}
		else {
			day++;
		}
	}
}
const Day Day::operator --() {
	if (common.isLeapYear(year)) {
		if (day < 1) {
			month--;
			if (month < 1) {
				year--;
				month = 12;
				day = normalDay[month];
			}
			else {
				day = leapDay[month];
			}
		}
		else {
			day--;
		}
	}
	else {
		if (day < 1) {
			month--;
			if (month < 1) {
				month = 12;
				if (common.isLeapYear(year - 1)) {
					day = leapDay[month];
				}
				else {
					day = normalDay[month];
				}
			}
			else {
				day = leapDay[month];
			}
		}
		else {
			day--;
		}
	}
}
const Day Day::operator +(const int inputDay) {
	if (common.isLeapYear(year)) {
		if (inputDay > 365) {

		}
		else if (inputDay > ) {

		}
	}
	}
	else {
		if (inputDay > 365) {

		}
		else if (inputDay > ) {

		}
	}
}
const Day Day::operator -(const int inputDay) {

}
istream& operator >>(istream&, Day&) {

}
ostream& operator <<(ostream&, Day&) {

}