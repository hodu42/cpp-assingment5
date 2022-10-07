#include <string>
#include <iostream>
#include "SentenceProcessing.h"

int main() {
	SentenceProcessing sp;

	sp.setSentenceFormat();

	cout << sp << endl;

	sp.printNumberOfAlpabets();
}