

#include <iostream>

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
            array[i][j] = rand() % 10+1;
        }
    }
}

void change_array(int** array, int s) {
    for (int i = 0;i < s;i++) {
        for (int j = 0;j < s - i - 1;j++) {
            int temp;
            temp = array[i][j];
            array[i][j] = array[s - j - 1][s - i - 1];
            array[s - j - 1][s - i - 1] = temp;
        }
    }

}
void free(int** array, int s) {
	delete[] array[0];
	delete[] array;
}

int main() {
    setlocale(LC_ALL, "Rus");
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
    cout << "Матрица симметричная относительно побочной диагонали" << endl;
    print_array(array, s);
    free(array,s);
    return 0;
}
