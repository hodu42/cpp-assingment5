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
// p는 크기가 MAX인 각 인자가 포인터인 배열을 가르키고, 각 인자에 arr[i]에 해당하는 주소를 넣음으로서 2차원 배열을 완성하여 출력할 수 있다.

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
//	print2DArr(p, MAX);			// print2DArr이라는 함수의 매개변수에는 이중포인터가 들어오도록 되어있는데 들어온 변수인 arr은 그냥 포인터이기 때문에 안되는 것 같다.
//	return 0;
//}//함수인자를 1차원 포인터의 배열로 하면 각 포인터는 2차원 배열의 행을 가르키고 그 행에서 열에 있는 값을 주소계산법을 사용해 출력할 수 있다.