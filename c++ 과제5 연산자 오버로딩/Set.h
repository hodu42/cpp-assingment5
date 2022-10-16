#pragma once
#include <iostream>

using namespace std;

class Set {
public:
	Set();
	const Set operator |(const Set) const;
	const Set operator &(const Set) const;
	void insert(const int);

private:
	int* p;
	int crtSize;
	int maxSize;
};
istream& operator >>(istream&, Set&);
ostream& operator <<(ostream&, const Set&);