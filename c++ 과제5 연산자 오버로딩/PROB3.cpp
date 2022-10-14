#include <iostream>

using namespace std;

void print2DArr(int** p, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << p[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	const int MAX = 3;
	int arr[MAX][MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int** p = new int* [MAX];

	for (int i = 0; i < MAX; i++) {
		p[i] = arr[i];
	}

	print2DArr(p, MAX);

	delete p;
	return 0;
}
// p�� ũ�Ⱑ MAX�� �� ���ڰ� �������� �迭�� ����Ű��, �� ���ڿ� arr[i]�� �ش��ϴ� �ּҸ� �������μ� 2���� �迭�� �ϼ��Ͽ� ����� �� �ִ�.

//void print2DArr(int* p[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//			cout << p[i][j] << " ";
//		cout << endl;
//	}
//	cout << endl;
//}
//int main()
//{
//	const int MAX = 3;
//	int arr[MAX][MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	
//	int* p[MAX];
//	for (int i = 0; i < MAX; i++) {
//		p[i] = arr[i];
//	}
//	
//	print2DArr(p, MAX);			// print2DArr�̶�� �Լ��� �Ű��������� ���������Ͱ� �������� �Ǿ��ִµ� ���� ������ arr�� �׳� �������̱� ������ �ȵǴ� �� ����.
//	return 0;
//}//�Լ����ڸ� 1���� �������� �迭�� �ϸ� �� �����ʹ� 2���� �迭�� ���� ����Ű�� �� �࿡�� ���� �ִ� ���� �ּҰ����� ����� ����� �� �ִ�.