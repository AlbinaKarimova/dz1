//Напишите функцию, которая вычисляет N-ое число Фибоначчи
#include<iostream>
using namespace std;
int main() {
	int N, i;
	cin >> N;
	int a = 1, b = 1;
	for (i = 1;i <= N;i++) {
		int c = a + b;
		a = b;
		b = c;
	}
	cout << "N" << " = " << b << endl;
	return 0;
}