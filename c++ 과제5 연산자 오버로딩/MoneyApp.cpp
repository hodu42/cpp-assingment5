#include <iostream>
#include "Money.h"
#include <string>

using namespace std;

int main() {
	Money m1, m2, END_AMOUNT(0, 0);

	while (m1.inputNreturn() != END_AMOUNT) {
		cout << "Input amount is " << m1.toString() << endl;
		m2.inputNreturn(); // $0.00 could be input
		cout << "Input amount is " << m2.toString() << endl;
		cout << m1.toString() << " + " << m2.toString() << " = " << (m1 + m2).toString() << endl;
		cout << m1.toString() << " - " << m2.toString() << " = " << (m1 - m2).toString() << endl;
		cout << m1.toString() << " == " << m2.toString() << " is ";
		if (m1 == m2) cout << "true" << endl;
		else cout << "false." << endl;
		cout << m1.toString() << " >= " << m2.toString() << " is ";
		if (m1 >= m2) cout << "true" << endl;
		else cout << "false." << endl;
		cout << m1.toString() << " <= " << m2.toString() << " is ";
		if (m1 <= m2) cout << "true" << endl;
		else cout << "false." << endl;
		cout << m1.toString() << " > " << m2.toString() << " is ";
		if (m1 > m2) cout << "true" << endl;
		else cout << "false." << endl;
		cout << m1.toString() << " < " << m2.toString() << " is ";
		if (m1 < m2) cout << "true" << endl;
		else cout << "false." << endl;
	}
	cout << "Stop with 0 0" << endl << " === END === ";
}
