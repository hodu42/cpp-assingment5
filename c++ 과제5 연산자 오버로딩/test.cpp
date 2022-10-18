#include <iostream>

using namespace std;

class A {
public:
	A();
	~A() {
		cout << "소멸자 호출 \n";
	}
	A(const A& a) {
		cout << "복사 생성자 호출 \n";
	}
	A operator =(const A& a) {
		cout << "대입 연산자 호출 \n";
	}
private:
};

A func1() {
	return A();
}
A func2(A& a) {
	return a;
}

int main() {
	A a;

	A b = func1();
}