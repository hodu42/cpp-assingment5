#pragma once

class Fraction {
public:
	Fraction();
	Fraction(int, int);
	void setDenom(int);
	void setNumer(int);
	Fraction add(Fraction) const;
	void print();
private:
	int denom, numer;
	void gcd(int, int);
	void denomCheck(int);
};
