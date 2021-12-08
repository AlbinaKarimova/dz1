/*Ввести с клавиатуры в одну строку фамилию, имя и отчество, разделив их пробелом.
Вывести фамилию и инициалы. Например, при вводе строки «Иванов Петр Семёнович»
должно получиться «П.С. Иванов».*/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
void FIO(char* s) {
    char* fio;
    fio = s;;
    while (*fio != ' ') {
        fio++;
    }
    cout << *++fio << ".";
    while (*fio != ' ') {
        fio++;
    }
    cout << *++fio << ".";
    fio = s;
    while (*fio != ' ') {
        cout << *fio++;
    }

}
int main() {
    setlocale(LC_ALL, "Rus");
    char s[256];
    cin.getline(s, 256);
    FIO(s);
    return 0;

}


