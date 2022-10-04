#include "DDay.h"
#include <string>
#include <cstdlib>

using namespace std;

const int MAXINPUT = 9;
bool getInput(char input[MAXINPUT]);
int main() {
	DDay currentDay;
	char input[MAXINPUT];

	cout << currentDay << endl;
	cout << "Move date(yyyymmdd, (tomorrow)+, (yesterday)-, set D-day(+/-int), Quit(Q/q)) : ";
	cin >> input;

	if ( isdigit(input[0]) ) {
		currentDay.setToday(input);
	}
	else {

	}

	cout << "=== END ===";
}
bool getInput(char input[MAXINPUT]) {
	cin >> input;
	return strcmp(input, "q");
}
