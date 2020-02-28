// task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <time.h>
using namespace std;

bool isInterupter(char c) {

	bool ansver = false;
	char interapter[] = " ";
	for (int i = 0; interapter[i]; i++) {
		if (interapter[i] == c) {
			ansver = true;
			break;
		}
	}

	return ansver;
}

int main()
{
	//srand(time(NULL));

	char c[100];
	cin.getline(c, 100);

	char* pc = c;

	int count = 0;
	for (int i = 0; *(pc+i); i++) {
		
		char symbol = *(pc + i);
		//cout << *(&(*pc)) << ' '  << symbol << ' ' << c[i]<< endl;
		if (isalpha(*pc+i) &&(i == 0 || isInterupter(*(pc+i-1) ))) {
			cout << i << ' ';;
			cout << (void*)pc << endl;
		}
	}

	return 0;
}