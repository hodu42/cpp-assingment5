#pragma once
#include <iostream>

using namespace std;

class Fraction {
public:
	Fraction();
	Fraction(int, int);
	const int getNumer() const;
	const int getDenom() const;
	void setDenom(int);
	void setNumer(int);
	const Fraction operator +(const Fraction&) const;
private:
	int denom, numer;
};
ostream& operator <<(ostream& outputStream, const Fraction& fraction);