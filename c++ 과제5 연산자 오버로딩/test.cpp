#include <iostream>

using namespace std;

class A {
public:
	A();
	~A() {
		cout << "�Ҹ��� ȣ�� \n";
	}
	A(const A& a) {
		cout << "���� ������ ȣ�� \n";
	}
	A operator =(const A& a) {
		cout << "���� ������ ȣ�� \n";
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