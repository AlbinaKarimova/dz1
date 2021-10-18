//Íàïèøèòå ôóíêöèþ, êîòîðàÿ âû÷èñëÿåò N-îå ÷èñëî Ôèáîíà÷÷è
#include<iostream>
using namespace std;
int main() {
	int N, i;
	cin >> N;
	int a = 1, b = 1;
	for (i = 2;i <= N;i++) {
		int c = a + b;
		a = b;
		b = c;
	}
	cout << "N" << " = " << a << endl;
	return 0;
}
