
#include<iostream>
using namespace std;
int random1(int N) {
    return rand() % N;
}
int random2(int M) {
    return rand() % M;
}
int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int n, m;
        n = rand() % 6 + 1;
        m = rand() % 6 + 1;
    cout << "Первый кубик = " << n << endl;
    cout << "Второй кубик = " << m << endl;
    return 0;
}
