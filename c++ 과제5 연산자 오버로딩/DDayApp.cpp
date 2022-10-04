#include "DDay.h"
#include <string>
#include <cstdlib>

using namespace std;

const int MAXINPUT = 9;
bool getInput(char input[MAXINPUT]);

int main() {
	DDay currentDay;
	char input[MAXINPUT];
	while (1) {
		cout << currentDay << endl;
		cout << "ÇöÀç inputÀº" << input << endl;
		cout << "Move date(yyyymmdd, (tomorrow)+, (yesterday)-, set D-day(+/-int), Quit(Q/q)) : ";
		cin >> input;

		if (isdigit(input[0])) {
			currentDay.setToday(input);
		}
		else {
			if (!strcmp(input, "+")) {
				currentDay.setToday(++currentDay.getToday());
			}
			else if (!strcmp(input, "-")) {
				currentDay.setToday(--currentDay.getToday());
			}
			else {
				int dday = atoi(input);
				currentDay.setDDayDate(dday);
			}
		}
	}
	/*cout << currentDay << endl;
	cout << "Move date(yyyymmdd, (tomorrow)+, (yesterday)-, set D-day(+/-int), Quit(Q/q)) : ";
	cin >> input;

	if ( isdigit(input[0]) ) {
		currentDay.setToday(input);
	}
	else {
		if (!strcmp(input, "+")) {
			currentDay.setToday(++currentDay.getToday());
		}
		else if (!strcmp(input, "-")) {
			currentDay.setToday(--currentDay.getToday());
		}
		else {
			int dday = atoi(input);
			currentDay.setDDayDate(dday);
		}
	}
	cout << currentDay << endl;*/

	cout << "=== END ===";
}
bool getInput(char input[MAXINPUT]) {
	cin >> input;
	return strcmp(input, "q");
}
