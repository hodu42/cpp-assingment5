#include "Set.h"

int main()
{
	Set s1, s2, resultSet;
	cout << "Input 2 sets of integers(Each set should end with a negative value)." << endl;
	cin >> s1 >> s2; 
	resultSet = s1 | s2;
	cout << "Union is " << resultSet << endl; // ������
	resultSet = s1 & s2;
	cout << "Intersection is " << resultSet << endl; // ������
	return 0;
}