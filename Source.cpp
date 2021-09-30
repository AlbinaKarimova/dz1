//Напишите программу, которая определяет, верно ли, что введенное число трехзначное
#include<iostream>
using namespace std;
int main() {
    setlocale(LC_ALL,"Rus");
    int a;
    cin >> a;
    if (a > 99 && a < 1000) 
        cout << "Верно";
    else 
        cout << "Неверно";
    return 0;
}
