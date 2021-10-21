/*Ќапишите рекурсивную процедуру дл€ перевода числа из
двоичной системы счислени€ в дес€тичную.*/
#include<iostream>
using namespace std;
int bin(int n,int k=1) {
		if (n > 0) {
			return bin((n / 10, k*2) + (n % 10) * k);
		}
		return 0;
}
int main() {
	int n ;
	cin >> n;
	cout << bin(n);
}