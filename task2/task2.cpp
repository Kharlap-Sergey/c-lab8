// Лабораторная работа № 8. Структуры

// Задание 2

// Вариант 3.

// Студента группы 10701219 Харлапа Сергея Александровича
#include <iostream>
using namespace std;

int main()
{
	int m[] = { 16,78,99,6,-29,19,-52,65,-88,51,
	-79,-22,32,-25,-62,-69,-2,-59,-75,89,
	-87,95,-22,85,-49,-75,76,73,-59,-52,
	30,9,-28,-48,0,57,-6,-85,0,-18,
	-97,-21,-95,64,22,-2,69,-84,-1,-71,
	-25,47,72,43,15,-44,44,61,4,74,
	88,-61,0,-64,-83,97,0,90,15,8,
	-54,19,73,35,-67,-87,85,-99,-70,10,
	98,58,-10,-29,95,62,77,89,36,-32,
	78,60,-79,-18,30,-13,-34,-92,1,-38 };
	int dm[50][2];

	int* p = m;
	int* dp = &dm[0][0];

	int sum = 0;
	for (p; p != (m + 100); p++, dp++) {
		*dp = *p;
	}

	dp = &dm[0][0];
	for (int i = 0; i < 50; i++) {
		sum = 0;
		double average;
		for (int j = 0; j < 2; j++, dp++) {
			sum += *dp;
		}
		average = sum / 2.0;
		cout << average << endl;
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
