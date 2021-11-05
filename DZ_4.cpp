
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


int random_n(int N2) {
	return rand() % N2 + 1;
}

void random_mas2(int a[], int size) {
	int N2;
	cin >> N2;
	for (int i = 0;i < size;i++) {
		a[i] = random_n(N2);
	}
}
void print_mas2(int a[], int size) {
	for (int i = 0;i < size - 1;i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}



void print_mas3(int mas[], int size) {
	for (int i = 0;i < size - 1;i++) {
		cout << mas[i] << " ";
	}
}

void random_mas3(int mas[], int size) {
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

	int const N1 = 15;
	int A1[N1];
	ap(A1, N1);
	print_array(A1, N1);

	int const N2 = 20;
	int A2[N2];
	random_n(N2);
	random_mas2(A2, N2);
	print_mas2(A2, N2);


	srand(time(NULL));
	int const N3 = 15;
	int mas[N3];
	random_mas3(mas, N3);
	kol(mas, N3);
	print_mas3(mas, N3);
	cout << endl;
	return 0;
}