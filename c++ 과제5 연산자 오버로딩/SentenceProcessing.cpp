//#include "SentenceProcessing.h"
//
//const int ASCII_OF_a = 97;
//const int ALPABET_LENGTH = 25;
//int number_of_alpabets[ALPABET_LENGTH] = { 0 };
//
//SentenceProcessing::SentenceProcessing() {
//	getline(cin, input);
//}
//string SentenceProcessing::getSentence() const {
//	return input;
//}
//void SentenceProcessing::printNumberOfAlpabets() const {
//	string allLower = input;
//	for (int i = 0; i < input.length(); i++) {
//		allLower[i] = tolower(input[i]);
//	}
//
//	for (int i = 0; i < allLower.length(); i++) {
//		if (allLower[i] != ' ') {
//			number_of_alpabets[int(allLower[i]) - ASCII_OF_a]++;
//		}
//	}
//
//	for (int i = 0; i < ALPABET_LENGTH; i++) {
//		if (number_of_alpabets[i] != 0) {
//			cout << "[" << char(i + ASCII_OF_a) << ":" << number_of_alpabets[i] << "] ";
//		}
//	}
//	cout << endl;
//}