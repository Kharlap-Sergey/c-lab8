// task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <time.h>
using namespace std;

char GetRandomCharecter() {
	return rand() % ('Z'-'A'+1) + 'A';
}

int main()
{
	srand(time(NULL));

	char c[10][10][10];

	char* pc = &c[0][0][0];
	void *adres[1000];
	void* *a = &adres[0];

	int count = 0;
	for (int i = 0; i < 1000; i++, pc++) {
		char boof = GetRandomCharecter();
		*pc = boof;
		if ( *pc == 'Z') {
			*(a+count) = &(*pc);
			count++;
		
		}
	}

	cout << count << endl;
	for (int i = 0; i < count; i++) {
		cout << *(a+i) << ' ';
	}
	return 0;
}