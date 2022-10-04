#include "DDay.h"

DDay::DDay() {
	today = Day();
	dDayDate = Day(0, 0, 0);
	dDay = 0;
}
Day DDay::getToday() const {
	return today;
}
Day DDay::getDDayDate() const {
	return dDayDate;
}
int DDay::getDDay() const {
	return dDay;
}
void DDay::setToday(char input[9]) {
	int year = int(input[0]) * 1000 + int(input[1]) * 100 + int(input[2]) * 10 + int(input[3]) * 1;
	int month = int(input[4]) * 10 + int(input[5]) * 1;
	int day = int(input[6]) * 10 + int(input[7]) * 1;
	today = Day(year, month, day);
	if (dDay != 0) {
		setDDayDate(dDay);
	}
}
void DDay::setToday(Day inputDay) {
	today = inputDay;
}
void DDay::setDDay(char input[9]) {

}
void DDay::setDDayDate(int inputDDay) {
	dDay = inputDDay;
	dDayDate = today + dDay;
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
			outputStream << "-" << dDay.getDDay() << "]";
		}
		outputStream << " " << dDay.getDDayDate();
	}
	return outputStream;
}