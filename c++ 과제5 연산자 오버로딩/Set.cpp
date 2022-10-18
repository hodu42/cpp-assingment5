#include "Set.h"
#include <math.h>

const int INITIALSIZE = 10;

Set::Set() { 
	p = new int[INITIALSIZE];
	crtSize = 0;
	maxSize = INITIALSIZE;
}

Set::Set(const int inputSize) {
	p = new int[inputSize];
	crtSize = 0;
	maxSize = inputSize;
}

Set::~Set() {
	delete[] p;
}

Set::Set(const Set& originSet) {
	crtSize = originSet.getCrtSize();
	maxSize = originSet.getMaxSize();

	p = new int[maxSize];

	for (int i = 0; i < crtSize; i++) {
		p[i] = originSet.p[i];
	}
}

int* Set::getSet() const{
	return p;
}

const int Set::getCrtSize() const {
	return crtSize;
}

const int Set::getMaxSize() const {
	return maxSize;
}

void Set::insert(const int inputNum, const bool isUnion) {
	int targetIdx = 0;

	if (crtSize == 0) {
		*p = inputNum;
		crtSize++;
	}
	else if ((targetIdx = binarySearch(p, inputNum, crtSize)) >= 0) {

		if (crtSize + 1 > maxSize) {
			copyArray(targetIdx);
		}
		else if (targetIdx < crtSize) {

			for (int i = crtSize; i > targetIdx; i--) {
				p[i] = p[i - 1];
			}
		}
		
		p[targetIdx] = inputNum;
		crtSize++;
	}
	else if (!isUnion) {
		cout << inputNum << " is deleted as a duplicated element." << endl;
	}
}

const Set Set::operator |(const Set set2) const {

	Set resultSet(*this);

	for (int i = 0; i < set2.crtSize; i++) {
		resultSet.insert(set2.p[i], 1);
	}

	return Set(resultSet);
}

const Set Set::operator &(const Set set2) const {

	Set resultSet(crtSize + set2.crtSize);

	for (int* crtIdx = set2.p; crtIdx < &set2.p[set2.crtSize]; crtIdx++) {

		if (binarySearch(p, *crtIdx, crtSize) == -1) {
			resultSet.insert(*crtIdx, 1);
		}
	}

	return Set(resultSet);
}

Set& Set::operator =(const Set& set2) {
	delete[] p;

	crtSize = set2.getCrtSize();
	maxSize = set2.getMaxSize();

	p = new int[maxSize];

	for (int i = 0; i < crtSize; i++) {
		p[i] = set2.p[i];
	}

	return *this;
}

void Set::copyArray(int targetIdx) {
	int* temp = p;
	p = new int[maxSize * 2];

	if (targetIdx < maxSize) {
		for (int i = 0; i < targetIdx; i++) {
			p[i] = temp[i];
		}
		for (int i = maxSize; i > targetIdx; i--) {
			p[i] = temp[i - 1];
		}
	}
	else if (targetIdx == maxSize) {
		for (int i = 0; i < maxSize; i++) {
			p[i] = temp[i];
		}
	}

	maxSize *= 2;
	delete[] temp;
}

istream& operator >>(istream& inputStream, Set& set) {
	int input = 1;

	while ((input = getInput(input, inputStream)) >= 0) {
		set.insert(input, 0);
	}

	return inputStream;
}

ostream& operator <<(ostream& outputStream, const Set& set) {
	const int setCrtSize = set.getCrtSize();
	const int* setArr = set.getSet();

	for (int i = 0; i < setCrtSize; i++) {
		outputStream << setArr[i] << " ";
	}

	return outputStream;
}

int binarySearch(int* p, int target, int maxSize) {
	int low = 0;
	int high = maxSize - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (p[mid] < target) {
			low = mid + 1;
		}
		else if (p[mid] > target) {
			high = mid - 1;
		}
		else {
			return -1;
		}
	}
	if (high < 0) {
		return 0;
	}
	else if (low > high) {
		return low;
	}
	return -1;
}

int getInput(int input, istream& inputStream) {
	inputStream >> input;
	return input;
}