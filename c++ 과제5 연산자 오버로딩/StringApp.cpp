#include <string>
#include <iostream>

using namespace std;

string getNumberOfAlpabets(const string input);
string getCorrectedSentence(const string input);
string getEncodedSentence(const string input, const int gapSize);

const int NUM_OF_DIGITS = 10;
const int ALPHABET_LENGTH = 26;

int main() {

	string input = "";
	int gapSize = 0;

	cout << "Input : ";
	getline(cin, input);
		
	cout << "Gap size : ";
	cin >> gapSize;

	cout << getNumberOfAlpabets(input) << endl;

	cout << "Corrected sentence ==> ";
	cout << getCorrectedSentence(input) << endl;

	cout << "  Encoded sentence ==> ";
	cout << getEncodedSentence(input, gapSize) << endl;

	return 0;
}

string getNumberOfAlpabets(const string input) {

	string num_of_alphabets = "";
	int arr_Number_of_alphabets[ALPHABET_LENGTH] = { 0 };

	for (int i = 0; i < input.length(); i++) {

		char tempChar = tolower(input[i]);

		if (!isspace(tempChar)) {

			if ('a' <= tempChar && tempChar <= 'z') {

				arr_Number_of_alphabets[tempChar - 'a']++;
			}

		}
	}

	for (int i = 0; i < ALPHABET_LENGTH; i++) {

		if (arr_Number_of_alphabets[i] != 0) {

			string alphabet;
			alphabet += char(i + 'a');

			string temp = "[" + alphabet + ":" + to_string(arr_Number_of_alphabets[i]) + "] ";
			num_of_alphabets.append(temp);
		}
	}

	return num_of_alphabets;
}

string getCorrectedSentence(const string input) {

	string resultStr = "";
	int crtPos = 0;

	for (int i = 0; i < input.length(); i++) {

		if (isspace(input[i])) {

			resultStr += input[i];
		}
		else {

			resultStr += toupper(input[i]);
			crtPos = i + 1;

			break;
		}
	}
	for (int i = crtPos; i < input.length(); i++) {
		resultStr += tolower(input[i]);
	}

	return resultStr;
}
string getEncodedSentence(const string input, const int gapSize) {
	
	string encodedStr = "";
	int temp_ASCII_Code = 0;

	for (int i = 0; i < input.length(); i++) {

		temp_ASCII_Code = input[i] + gapSize;

		if (isalpha(input[i])) {

			if (isupper(input[i])) {

				if ('A' <= temp_ASCII_Code && temp_ASCII_Code <= 'Z') {
					encodedStr += char(temp_ASCII_Code);
				}
				else if (temp_ASCII_Code > 'Z') {
					encodedStr += char(temp_ASCII_Code - ALPHABET_LENGTH);
				}
				else if (temp_ASCII_Code < 'A') {
					encodedStr += char(temp_ASCII_Code + ALPHABET_LENGTH);
				}
			}
			else {

				if ('a' <= temp_ASCII_Code && temp_ASCII_Code <= 'z') {
					encodedStr += char(temp_ASCII_Code);
				}
				else if (temp_ASCII_Code > 'z') {
					encodedStr += char(temp_ASCII_Code - ALPHABET_LENGTH);
				}
				else if (temp_ASCII_Code < 'a') {
					encodedStr += char(temp_ASCII_Code + ALPHABET_LENGTH);
				}
			}
		}
		else if (isdigit(input[i])) {

			if ('0' <= temp_ASCII_Code && temp_ASCII_Code <= '9') {
				encodedStr += char(temp_ASCII_Code);
			}
			else if (temp_ASCII_Code > '9') {
				encodedStr += char('0' + (temp_ASCII_Code - '0') % NUM_OF_DIGITS);
			}
			else if (temp_ASCII_Code < '0') {

				while (temp_ASCII_Code < '0') {
					temp_ASCII_Code += NUM_OF_DIGITS;
				}

				encodedStr += char(temp_ASCII_Code);
			}
		}
		else {
			encodedStr += input[i];
		}
	}

	return encodedStr;
}