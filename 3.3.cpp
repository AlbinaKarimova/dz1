//Напишите рекурсивную функцию, которая раскладывает число на простые сомножители.
#include<iostream>
using namespace std;
void F(int n, int i = 2) {
    while (n % i == 0) {
        cout << i << endl;
        n /= i;
    }
    if (n != 1) {
        F(n, i++);
    }
}
int main() {
    int x;
    cin >> x;
    F(x);
    return 0;
}