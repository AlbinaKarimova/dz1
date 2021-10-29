/*Заполните массив случайными числами в диапазоне 1000.2000 и подсчитайте число элементов, у которых вторая с конца цифра – чётная.*/
#include<iostream>
using namespace std;
void print_mas(int mas[], int size) {
	for (int i = 0;i < size - 1;i++) {
		cout << mas[i] << " ";
	}
}

void random_mas(int mas[], int size) {
	for (int i = 0;i < size;i++) {
		mas[i] = rand() % 1001 + 1000;
	}
}

void kol(int mas[], int size) {
	int k = 0;
	for (int i = 0;i < size - 1;i++) {
		if (mas[i] % 2 == 0) k++;
	}
	cout << "kol = " << k << endl;
}

int main() {
	srand(time(NULL));
	int const N = 15;
	int mas[N];
	random_mas(mas, N);
	kol(mas, N);
	print_mas(mas, N);
	cout << endl;
	return 0;
}