// Лабораторная работа № 8. Структуры

// Задание 3

// Вариант 3.

// Студента группы 10701219 Харлапа Сергея Александровича
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