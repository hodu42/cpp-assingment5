#pragma once
#include <iostream>

using namespace std;

class Set {
public:
	Set();
	Set(const int);
	~Set();
	Set(const Set&);
	int* getSet() const;
	const int getCrtSize() const;
	const int getMaxSize() const;
	const Set operator |(const Set) const;
	const Set operator &(const Set) const;
	Set& operator =(const Set&);
	void insert(const int, const bool);

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