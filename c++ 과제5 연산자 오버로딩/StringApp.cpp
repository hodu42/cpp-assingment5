#include <string>
#include <iostream>

using namespace std;

void printNumberOfAlpabets(string input);
void printCorrectedSentence(string input);
void printEncodedSentence(string input, int gapSize);

const int num_of_digits = 10;
const int ALPHABET_LENGTH = 26;

int main() {

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
	printEncodedSentence(input, gapSize);

	return 0;
}

void printNumberOfAlpabets(string input) {

	int arr_Number_of_alphabets[ALPHABET_LENGTH] = { 0 };

	for (int i = 0; i < input.length(); i++) {

		char tempChar = tolower(input[i]);

		if (!isspace(tempChar)) {

			if ('a' <= tempChar && tempChar <= 'z') {

				arr_Number_of_alphabets[tempChar - 'a']++;
			}

		}
	}

	bool is_First_Print = 1;

	for (int i = 0; i < ALPHABET_LENGTH; i++) {

		if (arr_Number_of_alphabets[i] != 0) {

			if (is_First_Print) {

				cout << "[" << char(i + 'a') << ":" << arr_Number_of_alphabets[i] << "]";

				is_First_Print = 0;
			}
			else {
				cout << " [" << char(i + 'a') << ":" << arr_Number_of_alphabets[i] << "]";
			}
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
void printEncodedSentence(string input, int gapSize) {
	
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

					temp_ASCII_Code %= ALPHABET_LENGTH;

					while (temp_ASCII_Code > 'Z' || temp_ASCII_Code < 'A') {

						temp_ASCII_Code += ALPHABET_LENGTH;
					}

					encodedStr += char(temp_ASCII_Code);
				}
				else if (temp_ASCII_Code < 'A') {

					temp_ASCII_Code %= ALPHABET_LENGTH;

					while (temp_ASCII_Code < 'A') {

						temp_ASCII_Code += ALPHABET_LENGTH;
					}

					encodedStr += char(temp_ASCII_Code);
				}
			}
			else {

				if ('a' <= temp_ASCII_Code && temp_ASCII_Code <= 'z') {
					encodedStr += char(temp_ASCII_Code);
				}
				else if (temp_ASCII_Code > 'z') {

					temp_ASCII_Code %= ALPHABET_LENGTH;

					while (temp_ASCII_Code > 'z' || temp_ASCII_Code < 'a') {

						temp_ASCII_Code += ALPHABET_LENGTH;
					}

					encodedStr += char(temp_ASCII_Code);
				}
				else if (temp_ASCII_Code < 'a') {

					temp_ASCII_Code %= ALPHABET_LENGTH;

					while (temp_ASCII_Code < 'a') {

						temp_ASCII_Code += ALPHABET_LENGTH;
					}

					encodedStr += char(temp_ASCII_Code);
				}
			}
		}
		else if (isdigit(input[i])) {

			if ('0' <= temp_ASCII_Code && temp_ASCII_Code <= '9') {
				encodedStr += char(temp_ASCII_Code);
			}
			else if (temp_ASCII_Code > '9') {

				temp_ASCII_Code %= num_of_digits;

				while (temp_ASCII_Code > '9' || temp_ASCII_Code < '0') {

					temp_ASCII_Code += num_of_digits;
				}

				encodedStr += char(temp_ASCII_Code);
			}
			else if (temp_ASCII_Code < '0') {

				temp_ASCII_Code %= num_of_digits;

				while (temp_ASCII_Code < '0') {
					temp_ASCII_Code += num_of_digits;
				}

				encodedStr += char(temp_ASCII_Code);
			}
		}
		else {
			encodedStr += input[i];
		}
	}

	cout << encodedStr << endl;
}