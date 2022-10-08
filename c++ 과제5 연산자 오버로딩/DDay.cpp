#include "DDay.h"
#include <string>

DDay::DDay() {
	today = Day();
	dDayDate = Day();
	dDay = 0;
}

const Day DDay::getToday() const {
	return today;
}

const Day DDay::getDDayDate() const {
	return dDayDate;
}

const int DDay::getDDay() const {
	return dDay;
}

void DDay::setToday(const string input) {

	int year = stoi(input.substr(0, 4));
	int month = stoi(input.substr(4, 2));
	int day = stoi(input.substr(6, 2));

	if (isValidDate(year, month, day)) {
		today = Day(year, month, day);
	}

	if (dDay != 0) {
		setDDayDate(dDay);
	}
}

void DDay::setToday(const Day inputDay) {

	today = inputDay;

	if (dDay != 0) {
		setDDayDate(dDay);
	}
}

void DDay::setDDayDate(const int inputDDay) {
	dDay = inputDDay;

	if (dDay > 0) {
		dDayDate = today + dDay;
	}
	else {
		dDayDate = today - abs(dDay);
	}
}

const DDay DDay::operator ++() {
	setToday(++today);
	return *this;
}

const DDay DDay::operator --() {
	setToday(--today);
	return *this;
}

ostream& operator <<(ostream& outputStream, const DDay& dDay) {

	outputStream << "[Date] " << dDay.getToday();
	outputStream << " [D-day:";
	if (dDay.getDDay() == 0) {
		outputStream << "NONE] -";
	}
	else {
		if (dDay.getDDay() > 0) {
			outputStream << "+" << dDay.getDDay() << "]";
		}
		else {
			outputStream << dDay.getDDay() << "]";
		}
		outputStream << " " << dDay.getDDayDate();
	}

	return outputStream;
}