
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

bool get_polyndrom(char* str) {
    auto size = strlen(str);
    bool i = true;
    for (int j = 0; j < size / 2;j++) {
        if (str[j] != str[size - 1 - j]) {
            i = false;
            break;
        }
    }
    return i;
}

int main() {
    setlocale(LC_ALL, "Rus");
    char str[256];
    cin.getline(str, 256);
    if (get_polyndrom(str)) {
        cout << "Полиндром" << endl;
    }
    else {
        cout << "Не полиндром" << endl;
    }
    return 0;
}
