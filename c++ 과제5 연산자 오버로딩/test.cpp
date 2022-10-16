#include <iostream>

using namespace std;

int main() {
	const int MAX = 5;
	int arr[MAX] = { 1, 2, 3, 4, 5 };
	int* p = arr;
	p[0] = 10;
	p[1] = 20;

	for (int i = 0; i < MAX; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}