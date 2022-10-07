#pragma once
#include <string>
#include <iostream>

using namespace std;

class SentenceProcessing {
public:
	SentenceProcessing();
	string getSentence() const;
	void printNumberOfAlpabets() const;
	void setSentenceFormat();
	void printEncryptedSentence() const;

private:
	string input;
	int gapSize;
};
istream& operator >>(istream&, const SentenceProcessing&);
ostream& operator <<(ostream&, const SentenceProcessing&);

