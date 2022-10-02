#include <math.h>
#include "Util.h"

Util::Util() {
	return;
}
int Util::getGcd(int num1, int num2) {
	int small = 0, gcd = 1;
	if (abs(num2) >= abs(num1)) {
		small = abs(num1);
	}
	else {
		small = abs(num2);
	}
	for (int i = 2; i <= small; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			gcd = i;
		}
	}
	return gcd;
}