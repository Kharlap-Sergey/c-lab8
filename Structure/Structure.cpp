// Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;

struct NOTE
{
    char firstName[20];
    char secondName[20];
    char phonenumber[20];
    int birthday[3];
};

const int AmountPeople = 2;
NOTE newDictionaryOfpeople[AmountPeople];

bool CompareNOTE(NOTE first, NOTE second);

void Sort(NOTE* array, int len);

int ParseDate(char* date, int len);

void Read(NOTE* array, int len);

void Print(NOTE* array, int len);

NOTE IdentifyPeopleByFinenomber(NOTE* array, int len, char phonenumber[20]);
void PrintNOTEPattern(NOTE newNOTE);
int main();
//bool CompareNOTE(NOTE first, NOTE second) {
//    auto resultOfComparingFirstNames = strcmp(first.firstName, second.firstName);
//    bool ansver = (bool)resultOfComparingFirstNames;
//    if (resultOfComparingFirstNames == 0) {
//        ansver = (bool)strcmp(first.secondName, second.secondName);
//    }
//
//    return ansver;
//}

//void Sort(NOTE *array, int len) {
//    
//    for (int i = 0; i < len-1; i++) {
//        for (int j = 0; j < len; j++) {
//            if (CompareNOTE(array[i], array[j])) {
//                auto boof = array[i];
//                array[i] = array[j];
//                array[j] = boof;
//            }
//        }
//    }
//}

//int ParseDate(char* date, int len) {
//    int ans = 0;
//    for (int i = 0; i < len; i++) {
//        if (date[i] >= '0' && date[i] <= '9') {
//            int number = (int)(date[i] - '0');
//            ans = ans*10 + number;
//        }
//    }
//    return ans;
//}

//void Read(NOTE *array, int len) {
//    for (int i = 0; i < len; i++) {
//        NOTE newNOTE;
//
//        cin.getline(newNOTE.firstName, 20, ' ');
//        cin.getline(newNOTE.secondName, 20, ' ');
//        cin.getline(newNOTE.fonnumber, 20, ' ');
//        char boof[20];
//        cin.getline(boof, 15);
//        int date = ParseDate(boof, 15);
//        
//        newNOTE.birthday[2] = date % 10000;
//        date /= 10000;
//        newNOTE.birthday[1] = date % 100;
//        date /= 100;
//        newNOTE.birthday[0] = date;
//        array[i] = newNOTE;
//    }
//}

//void Print(NOTE* array, int len) {
//    for (int i = 0; i <  len; i++) {
//        NOTE newNOTE;
//        newNOTE = array[i];
//        puts(newNOTE.firstName);
//        puts(newNOTE.secondName);
//        puts(newNOTE.fonnumber);
//        cout << newNOTE.birthday[0] << '.' << newNOTE.birthday[1] << '.' << newNOTE.birthday[2] <<endl;
//    }
//}

void DofirstTask() {
    
    cout << "if yout wonna refresh or create list enter 1\n if you wonna \
identify people enter 2\n for print all information enter 3\n else program will end";

    int  choice;
    cin >> choice;

    if (choice == 1) {
        cout << "enter FirstName SecondName fonenumber and birthday date\n";
        Read(newDictionaryOfpeople, AmountPeople);

    }
    else if (choice == 2) {
        cout << "enter Phone number\n";
        char phonenumber[20];
        cin >> phonenumber;

        auto res = IdentifyPeopleByFinenomber(newDictionaryOfpeople, AmountPeople, phonenumber);

        if (strcmp(res.firstName, "NON") != 0) {
            PrintNOTEPattern(res);
        }
        else {
            cout << "Found error!\n";
        }
    }
    else if (choice == 3) {
        Sort(newDictionaryOfpeople, AmountPeople);
        Print(newDictionaryOfpeople, AmountPeople);
    }
    else return;
    DofirstTask();
}

int main()
{
    DofirstTask();
}

int strcmp(char* A, char* B) {

    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] > B[i])
            return 1;
        if (A[i] < B[i])
            return -1;
    }

    for (int i = 0; B[i] != '\0'; i++) {
        if (A[i] > B[i])
            return 1;
        if (A[i] < B[i])
            return -1;
    }

    return 0;
}

bool CompareNOTE(NOTE first, NOTE second) {

    /// return True if first upper  then second
    int resultOfComparingFirstNames = strcmp(first.firstName, second.firstName);
    //cout << resultOfComparingFirstNames << endl;
    if (resultOfComparingFirstNames == -1)
        return false;
    else if (resultOfComparingFirstNames == 1)
        return true;
    else {
        resultOfComparingFirstNames = strcmp(first.secondName, second.secondName);
        if (resultOfComparingFirstNames == -1)
            return false;
        else if (resultOfComparingFirstNames == 1)
            return true;
    }
}

void Sort(NOTE* array, int len) {
   
    for (int i = 0; i < len - 1; i++) {
        for (int j = i+1; j < len; j++) {
            if (CompareNOTE(array[i], array[j])) {
                auto boof = array[i];
                array[i] = array[j];
                array[j] = boof;
            }
        }
    }
}

int ParseDate(char* date, int len) {
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (date[i] >= '0' && date[i] <= '9') {
            int number = (int)(date[i] - '0');
            ans = ans * 10 + number;
        }
    }
    return ans;
}

void Read(NOTE* array, int len) {
    for (int i = 0; i < len; i++) {
        NOTE newNOTE;

        char boof[20];
        getchar();
        cin.getline(newNOTE.firstName, 20, ' ');
        cin.getline(newNOTE.secondName, 20, ' ');
        cin.getline(newNOTE.phonenumber, 20, ' ');
        //cout << -1;
        cin.getline(boof, 15);
        //cout << -2;
        int date = ParseDate(boof, 15);

        newNOTE.birthday[2] = date % 10000;
        date /= 10000;
        newNOTE.birthday[1] = date % 100;
        date /= 100;
        newNOTE.birthday[0] = date;
        array[i] = newNOTE;
        ///cout << -1;
    }
}

void PrintNOTEPattern(NOTE newNOTE) {
    puts(newNOTE.firstName);
    puts(newNOTE.secondName);
    puts(newNOTE.phonenumber);
    cout << newNOTE.birthday[0] << '.' << newNOTE.birthday[1] << '.' << newNOTE.birthday[2] << endl;
}

NOTE IdentifyPeopleByFinenomber(NOTE* array, int len, char phonenumber[20]) {
    NOTE newNOTE;

    char boof[20] = "NON/0";
    newNOTE = {"NON", "", ""};

    for (int i = 0; i < len; i++) {
        if (strcmp(array[i].phonenumber, phonenumber) == 0) {
            newNOTE = array[i];
            break;
        }
    }

    return newNOTE;
}
void Print(NOTE* array, int len) {
    for (int i = 0; i < len; i++) {
        NOTE newNOTE;
        newNOTE = array[i];
        
        PrintNOTEPattern(newNOTE);
    }
}
