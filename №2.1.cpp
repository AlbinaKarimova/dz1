/*Напишите функцию, которая моделирует бросание двух игральных
кубиков(на каждом может выпасть от 1 до 6 очков).
(Используйте генератор псевдослучайных чисел.)*/
#include<iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Rus");
    int n, m;
    srand(time(0));
    n = 1 + rand() % 6;
    m = 1 + rand() % 6;
    cout << "Первый кубик = " << n << endl;
    cout << "Второй кубик = " << m << endl;
    return 0;
}