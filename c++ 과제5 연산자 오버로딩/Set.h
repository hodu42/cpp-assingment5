#pragma once
#include <iostream>

using namespace std;

class Set {
public:
	Set();
	Set(const int);
	int* getSet() const;
	void del() const;
	const int getCrtSize() const;
	const Set operator |(const Set) const;
	const Set operator &(const Set) const;
	void insert(const int, const bool);
	const int intersection(const int);

private:
	int* p;
	int crtSize;
	int maxSize;
	void copyArray(const int);
};
istream& operator >>(istream&, Set&);
ostream& operator <<(ostream&, const Set&);
int getInput(int, istream&);
int binarySearch(int*, int, int);