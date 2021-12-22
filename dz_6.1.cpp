#include<iostream>
using namespace std;
void print_array(int** array, int s) {
	for (int i = 0;i < s;i++) {
		for (int j = 0;j < s;j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void random_array(int** array, int s) {
	for (int i = 0;i < s;i++) {
		for (int j = 0;j < s;j++) {
			array[i][j] = rand() % 10 + 1;
		}
	}
}
void change_array(int** array, int s) {
	int i_min = 0, j_min = 0;
	for (int i = 0;i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (array[i][j] < array[i_min][j_min]) {
				i_min = i;
				j_min = j;
			}
		}
	}
	for (int i = i_min;i < s - 1;i++) {
		for (int j = 0;j < s; j++) {
			array[i][j] = array[i + 1][j];
		}
	}
	for (int j = j_min;j < s; j++) {
		for (int i = 0;i < s; i++) {
			array[i][j] = array[i][j + 1];
		}
	}
	s--;
	for (int i = 0;i < s;i++) {
		for (int j = 0;j < s;j++) {
			cout << array[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	srand(time(NULL));
	int s;
	cin >> s;
	int** array = new int* [s];
	for (int i = 0;i < s;i++) {
		array[i] = new int[s];
	}
	random_array(array, s);
	print_array(array, s);
	change_array(array, s);
	return 0;
}