#include <iostream>

using namespace std;

void print1DArr(int arr[], int arrMax);

int main()
{
	const int MAX = 5;
	int arr1[MAX] = { 1,2,3,4,5 }, arr2[MAX], * p;
	
	/*arr2 = arr1;*/		// arr1�� �޸𸮿����� arr1�� ù��°�ε��� �ּҸ� ��ȯ�Ѵ� �׸��� arr2���� �޸𸮿����� arr2�� �ּҸ� �������� ������ ������ �Ұ����ϴ�.
	for (int i = 0; i < MAX; i++) {
		arr2[i] = arr1[i];
	}

	//p = arr1; p�� arr1�� ���纻. // ������ p�� arr1�� �ּҸ� ����Ű�� ������ �����ߴ���� ��������ʴ´�.
	p = new int[MAX];
	for (int i = 0; i < MAX; i++) {
		p[i] = arr1[i];
	}

	/*p[0] = 99;*/ // p[0]�� ����. arr1�� �� �ٲ��� �� / ���� �ڵ忡���� p�� arr1[0]�� ����Ű�� �ֱ⶧���� arr1[0] = 99�� �ȴ�.
	p[0] = 99;
	
	/*print1DArr(arr1, MAX);
	print1DArr(arr2, MAX);
	print1DArr(p, MAX);*/		// print1DArr�̶�� �Լ��� ��� ������ ������ �߻��Ѵ�.
	print1DArr(arr1, MAX);
	print1DArr(arr2, MAX);
	print1DArr(p, MAX);

	delete[] p;

	return 0;
}

void print1DArr(int arr[], int arrMax) {
	for (int i = 0; i < arrMax; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}