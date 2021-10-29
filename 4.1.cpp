/*Заполните массив элементами арифметической прогрессии.
Её первый элемент и разность нужно ввести с клавиатуры.*/
#include<iostream>
using namespace std;
void print_array(int a[], const int size) {
	for (int i = 0;i < size;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void ap(int a[], const int size) {
	int d;
	cin >> a[0] >> d;
	for (int i = 1;i < size;i++) {
		a[i] = a[i - 1] + d;
	}

}

int main() {
	int const n = 15;
	int a[n];
	ap(a, n);
	print_array(a, n);
	return 0;
}
