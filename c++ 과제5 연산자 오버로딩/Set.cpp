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

int* Set::getSet() const{
	return p;
}

void Set::del() const {
	delete[] p;
}

const int Set::getCrtSize() const {
	return crtSize;
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

const int Set::intersection(const int inputNum) {
	int targetIdx = 0;

	if (crtSize == 0) {
		*p = inputNum;
		crtSize++;
		return -1;
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
		return -1;
	}
	else {
		return inputNum;
	}
}

const Set Set::operator |(const Set set2) const {
	const int set2CrtSize = set2.getCrtSize();
	const int* set2Arr = set2.getSet();

	Set resultSet(crtSize + set2CrtSize);
	
	for (int i = 0; i < crtSize; i++) {
		resultSet.insert(p[i], 1);
	}

	for (int i = 0; i < set2CrtSize; i++) {
		resultSet.insert(set2Arr[i], 1);
	}

	return resultSet;
}

const Set Set::operator &(const Set set2) const {
	const int set2CrtSize = set2.getCrtSize();
	const int* set2Arr = set2.getSet();

	Set tempSet(crtSize + set2CrtSize);
	Set resultSet(crtSize + set2CrtSize);
	int temp = 0;

	for (int i = 0; i < crtSize; i++) {
		tempSet.insert(p[i], 0);
	}
	for (int i = 0; i < set2CrtSize; i++) {
		if ((temp = tempSet.intersection(set2Arr[i])) >= 0) {
			resultSet.insert(temp, 0);
		}
	}

	tempSet.del();

	return resultSet;
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