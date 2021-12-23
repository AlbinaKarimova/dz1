#include <iostream>
using namespace std;
void random_array(int** array, int str,int stl) {
    for (int i = 0;i < str;i++) {
        for (int j = 0;j < stl;j++) {
            array[i][j] = rand() % 10;
        }
    }

}

void print_array(int** array, int str,int stl) {
    for (int i = 0;i < str;i++) {
        for (int j = 0;j < stl;j++) {
            cout << array[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

void delete_array(int** array, int str) {
    for (int i = 0;i < str;i++) {
        delete[] array[i];
    }
    delete[] array;
}

int find_max(int* array, int str){
    int max = array[0];
    for (int i = 1; i < str; i++){
        if (array[i] > max) max = array[i];
    }
    return(max);
}

int find_min_index(int* array, int str){
    int min = 0;
    for (int i = 1; i < str; i++) {
        if (array[i] < array[min]) min = i;
    }
    return(min);
}

int main(){
    srand(time(NULL));
    int str,stl;
    cin >> str>>stl;
    int** array = new int* [str];
    for (int i = 0;i < str;i++) {
        array[i] = new int[stl];
    }
    random_array(array, str,stl);
    print_array(array, str,stl);
    for (int i = str - 1; i >= 1; i--)
    {
        int temp;
        temp = find_min_index(array[i], stl);
        array[i][temp] = find_max(array[i - 1], str);
    }
    print_array(array, str, stl);
    delete_array(array, str);
}