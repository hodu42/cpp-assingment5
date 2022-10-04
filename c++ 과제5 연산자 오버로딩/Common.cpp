#include "Common.h"

Common::Common() {
	return;
}
bool Common::isLeapYear(int inputYear) {
	return ((inputYear % 4 == 0 && inputYear % 100 != 0) || inputYear % 400 == 0);
}