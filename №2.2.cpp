
#include<iostream>
using namespace std;
void F(int &N) {
    int a = 1, b = 1;
    for (int i = 2;i <= N;i++) {
        int c;
        c = a + b;
        a = b;
        b = c;
    }
    cout << "N = " << a;
}
int main() {
    int N;
    cin >> N;
    F(N);
   return 0;
}
