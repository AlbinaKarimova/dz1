#include<iostream>
using namespace std;
int R(int& n, int c) {
    if (n / c) R(n, c * 10);
    c = c / 10;
    cout << n / c << " ";
    n = n % c;
    return 0;
}
int main() {
    int n;
    cin >> n;
    R(n, 10);
    cout << endl;
}