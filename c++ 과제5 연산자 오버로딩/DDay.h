#pragma once
#include "Day.h"

class DDay {
public:
	DDay();
	const Day getToday() const;
	const Day getDDayDate() const;
	const int getDDay() const;
	void setToday(const string);
	void setToday(const Day);
	void setDDayDate(const int);
	const DDay operator ++();
	const DDay operator --();
private:
	Day today;
	Day dDayDate;
	int dDay;
};
ostream& operator <<(ostream&, const DDay&);