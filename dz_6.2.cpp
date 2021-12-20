#include <iostream>

using namespace std;
void random_array(int** array, int s) {
    for (int i = 0;i < s;i++) {
        for (int j = 0;j < s;j++) {
            array[i][j] = rand() % 10;
        }
    }

}

void pr(int** array1, int** array2, int** array3, int s) {
    for (int i = 0;i < s;i++) {
        for (int j = 0;j < s;j++) {
            array3[i][j] = 0;
            for (int l = 0;l < s;l++) {
                array3[i][j] += array1[i][l] * array2[l][j];
            }

            cout << endl;
        }
    }

}

void print_array(int** array, int s) {
    for (int i = 0;i < s;i++) {
        for (int j = 0;j < s;j++) {
            cout << array[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int s;
    cin >> s;
    int** array1 = new int* [s];
    for (int i = 0;i < s;i++) {
        array1[i] = new int[s];
    }

    int** array2 = new int* [s];
    for (int i = 0;i < s;i++) {
        array2[i] = new int[s];
    }

    int** array3 = new int* [s];
    for (int i = 0;i < s;i++) {
        array3[i] = new int[s];
    }
    random_array(array1, s);
    random_array(array2, s);

    cout << "First array: ";
    cout << endl;

    print_array(array1, s);

    cout << "Second array: ";
    cout << endl;

    print_array(array2, s);
    pr(array1, array2, array3, s);

    cout << "Multiplication: ";
    cout << endl;

    print_array(array3, s);
    return 0;
}
