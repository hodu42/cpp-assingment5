#include <iostream>
#include "Money.h"

Money::Money() {
	dollars = 0;
	cents = 0;
}
Money::Money(int inputDollar, int inputCents) {
	setDollarsAndCents(inputDollar, inputCents);
}
int Money::getDollars() const {
	return dollars;
}
int Money::getCents() const {
	return cents;
}
void Money::setDollars(int inputDollars) {
	dollars = inputDollars;
}
void Money::setCents(int inputCents) {
	setDollarsAndCents(dollars, inputCents);
}
Money Money::inputNreturn() {
	cout << "Input dollars and cents : ";
	cin >> dollars >> cents;
	setDollarsAndCents(dollars, cents);
	return Money(dollars, cents);
}
string Money::toString() const {
	string str = "$" + to_string(dollars) + '.' + to_string(cents);
	return str;
}
void Money::setDollarsAndCents(int inputDollars, int inputCents) {
	if (inputCents >= 100) {
		dollars = inputDollars + (inputCents / 100);
		cents = inputCents % 100;
	}
	else {
		dollars = inputDollars;
		cents = inputCents;
	}
}
const Money Money::operator +(const Money& secondMoney) const {
	int totalDollars = dollars + secondMoney.getDollars();
	int totalCents = cents + secondMoney.getCents();
	return Money(totalDollars, totalCents);
}
const Money Money::operator -(const Money& secondMoney) const {
	int m1ToCents = dollars * 100 + cents;
	int m2ToCents = secondMoney.getDollars() * 100 + secondMoney.getCents();
	int resultCents = m1ToCents - m2ToCents;
	int totalDollars = resultCents / 100;
	int totalCents = resultCents % 100;
	return Money(totalDollars, totalCents);
}
const bool Money::operator ==(const Money& secondMoney) const {
	int m1ToCents = dollars * 100 + cents;
	int m2ToCents = secondMoney.getDollars() * 100 + secondMoney.getCents();
	return (m1ToCents == m2ToCents);
}
const bool Money::operator !=(const Money& secondMoney) const {
	int m1ToCents = dollars * 100 + cents;
	int m2ToCents = secondMoney.getDollars() * 100 + secondMoney.getCents();
	return (m1ToCents != m2ToCents);
}
const bool Money::operator >=(const Money& secondMoney) const {
	int m1ToCents = dollars * 100 + cents;
	int m2ToCents = secondMoney.getDollars() * 100 + secondMoney.getCents();
	return (m1ToCents >= m2ToCents);
}
const bool Money::operator <=(const Money& secondMoney) const {
	int m1ToCents = dollars * 100 + cents;
	int m2ToCents = secondMoney.getDollars() * 100 + secondMoney.getCents();
	return (m1ToCents <= m2ToCents);
}
const bool Money::operator >(const Money& secondMoney) const {
	int m1ToCents = dollars * 100 + cents;
	int m2ToCents = secondMoney.getDollars() * 100 + secondMoney.getCents();
	return (m1ToCents > m2ToCents);
}
const bool Money::operator <(const Money& secondMoney) const {
	int m1ToCents = dollars * 100 + cents;
	int m2ToCents = secondMoney.getDollars() * 100 + secondMoney.getCents();
	return (m1ToCents < m2ToCents);
}