#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
void print_array(T* array, const int size){
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
bool check_str(T a, T b){
    return to_string(a) > to_string(b);
}

int get_len(int x){
    if (x == 0) return 1;
    int k = 0;
    while (x > 0) {
        x =x / 10;
        k++;
    }
    return k;
}

template <typename T>
T get_max(T a, T b){
    if (a > b) return a;
    else return b;
}

bool check_double(double a, double b){
    if (a * b <= 0) return a > b;
    a = abs(a);
    b = abs(b);
    int a_whole = (int)a, b_whole = (int)b;
    int a_w_len = get_len(a_whole);
    int b_w_len = get_len(b_whole);
    int max_len = get_max(a_w_len, b_w_len);
    int cmp1 = (int)(a * pow(10, max_len - a_w_len) - b * pow(10, max_len - b_w_len));
    if (cmp1 < 0) return false;
    else if (cmp1 > 0) return true;
    int cmp2 = a_whole - b_whole;
    if (cmp2 < 0) return false;
    else if (cmp2 > 0) return true;
    double a_frac = a - a_whole;
    double b_frac = b - b_whole;
    double cmp3 = a_frac - b_frac;
    if (cmp3 < 0) return false;
    else if (cmp3 > 0) return true;
    return false;
}


typedef bool (*comparator)(double a, double b);

void sort_bubble(double* A, int size, comparator cmp){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++) {
            if (cmp(A[j], A[j + 1])) {
                double c = A[j];
                A[j] = A[j + 1];
                A[j + 1] = c;
            }
        }
}

template <typename T>
void fill_array(T* A, int N){
    while (N-- > 0)
        cin >> *(A++);
}

int main(){
    int N;
    cin >> N;
    double* A = new double[N];
    comparator str_double = check_double;
    comparator str = check_str;
    fill_array(A, N);
    cout << "double_sort:" << endl;
    sort_bubble(A, N, str_double);
    print_array(A, N);
    cout << "sort_string:" << endl;
    sort_bubble(A, N, str);
    print_array(A, N);
    cout << endl;
    delete[] A;
    return 0;
}