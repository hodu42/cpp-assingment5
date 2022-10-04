#pragma once
#include "Day.h"

class DDay {
public:
	DDay();
	Day getToday() const;
	Day getDDayDate() const;
	int getDDay() const;
	void setToday(char[9]);
	void setToday(Day);
	void setDDay(char[9]);
	void setDDayDate(int);
private:
	Day today;
	Day dDayDate;
	int dDay;
};
ostream& operator <<(ostream&, const DDay&);