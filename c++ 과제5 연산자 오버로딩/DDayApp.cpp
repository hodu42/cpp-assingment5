#include "DDay.h"
#include <cstdlib>
#include <string>

using namespace std;

string getInput(string input, DDay crtDay);

int main() {

	DDay currentDay;
	string input = "";

	while ((input = getInput(input, currentDay)) != "q") {

		if (input.length() >= 2) {
			if (isdigit(input[0])) {
				currentDay.setToday(input);	
			}
			else {
				int num = stoi(input);
				currentDay.setDDayDate(num);
			}
		}
		else {
			switch (input[0]) {

				case '+':
					++currentDay;
					break;

				case '-':
					--currentDay;
					break;
			}
		}
	}

	cout << "=== END ===";
}

string getInput(string input, DDay crtDay) {

	cout << crtDay << endl;
	cout << "Move date(yyyymmdd, (tomorrow)+, (yesterday)-, set D-day(+/-int), Quit(Q/q)) : ";
	cin >> input;

	return input;
}