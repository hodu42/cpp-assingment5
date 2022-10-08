#include <string>
#include <iostream>

using namespace std;

void printNumberOfAlpabets(string input);
void printCorrectedSentence(string input);

int main() {
	/*SentenceProcessing sentence;

	cin >> sentence;

	sentence.getCorrectedSentence();

	cout << sentence << endl;

	sentence.printNumberOfAlpabets();*/
	
	string input = "";
	int gapSize = 0;
	
	cout << "Input : ";
	getline(cin, input);
	
	cout << "Gap size : ";
	cin >> gapSize;

	printNumberOfAlpabets(input);

	cout << "Corrected sentece ==> ";
	printCorrectedSentence(input);

	cout << "  Encoded sentece ==> ";
	
}

void printNumberOfAlpabets(string input) {

	const int ALPHABET_LENGTH = 25;
	int number_of_alpabets[ALPHABET_LENGTH] = { 0 };

	for (int i = 0; i < input.length(); i++) {
		if (!isspace(tolower(input(i)) {
			number_of_alpabets[allLower[i] - 'a']++;
		}
	}

	for (int i = 0; i < ALPHABET_LENGTH; i++) {
		if (number_of_alpabets[i] != 0) {
			cout << "[" << char(i + 'a') << ":" << number_of_alpabets[i] << "] ";
		}
	}

	cout << endl;
}

void printCorrectedSentence(string input) {

	string resultStr = "";
	int crtPos = 0;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] != ' ') {
			resultStr += toupper(input[i]);
			crtPos = i + 1;
			break;
		}
	}
	for (int i = crtPos; i < input.length(); i++) {
		resultStr += tolower(input[i]);
	}

	cout << resultStr << endl;
}