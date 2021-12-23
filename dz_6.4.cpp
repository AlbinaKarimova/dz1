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
	for (int i = 0;i < s;i++) {
		for (int j = 0;j < s;j++) {
			if (i != i_min && j != j_min) {
				int temp;
				temp = array[i][j_min];
				array[i][j_min] = array[i_min][j];
				array[i_min][j] = temp;
			}
		}

	}
}

void delete_array(int **array,int s){
    for(int i=0;i<s;i++){
        delete [] array[i];
    }
    delete [] array;
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int s;
	cin >> s;
	int** array = new int* [s];
	for (int i = 0;i < s;i++) {
		array[i] = new int[s];
	}
	random_array(array, s);
	cout << "Исходная матрица" << endl;
	print_array(array, s);
	change_array(array, s);
	cout << "Матрица после пребразований" << endl;
	print_array(array,s);
	delete_array(array,s);
	return 0;
}
