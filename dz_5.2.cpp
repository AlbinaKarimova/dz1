//2
#include <iostream>
using namespace std;

int get_sum(char* s) {
	int sum = 0;
	while (char* part = strtok(s, "+")) {
		int a;
		a = atoi(part);
		sum += a;
		s = nullptr;
	}
	return sum;
}

int main() {
	char s[255];
	cin >> s;
	int sum = get_sum(s);
	cout << sum << endl;
	return 0;

}