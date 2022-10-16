#include <iostream>

using namespace std;

void print1DArr(int arr[], int arrMax);

int main()
{
	const int MAX = 5;
	int arr1[MAX] = { 1,2,3,4,5 }, arr2[MAX], * p;
	
	/*arr2 = arr1;*/		// arr1은 메모리에서의 arr1의 첫번째인덱스 주소를 반환한다 그리고 arr2또한 메모리에서의 arr2의 주소를 가져오기 때문에 대입이 불가능하다.
	for (int i = 0; i < MAX; i++) {
		arr2[i] = arr1[i];
	}

	//p = arr1; p는 arr1의 복사본. // 포인터 p가 arr1의 주소를 가리키기 때문에 예상했던대로 복사되지않는다.
	p = new int[MAX];
	for (int i = 0; i < MAX; i++) {
		p[i] = arr1[i];
	}

	/*p[0] = 99;*/ // p[0]를 수정. arr1은 안 바뀌어야 함 / 현재 코드에서는 p가 arr1[0]을 가리키고 있기때문에 arr1[0] = 99가 된다.
	p[0] = 99;
	
	/*print1DArr(arr1, MAX);
	print1DArr(arr2, MAX);
	print1DArr(p, MAX);*/		// print1DArr이라는 함수가 없어서 컴파일 오류가 발생한다.
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