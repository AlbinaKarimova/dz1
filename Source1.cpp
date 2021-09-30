//Напишите программу, которая вводит номер месяца и день и определяет,
//сколько дней осталось до Нового года. При вводе неверных данных должно
//быть выведено сообщение об ошибке.
#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	setlocale(LC_ALL, "Rus");
	switch (a) {
	case 1:
		cout << 365 - (31 - (31 - b)) << endl;break;
	case 3:
		cout << 365 - ((28 + (2 * 31)) - (31 - b)) << endl; break;
	case 5:
		cout << 365 - ((28 + (3 * 31) + 30) - (31 - b)) << endl; break;
	case 7:
		cout << 365 - ((28 + (4 * 31) + (30 * 2)) - (31 - b)) << endl; break;
	case 8:
		cout << 365 - ((28 + (5 * 31) + (30 * 2)) - (31 - b)) << endl; break;
	case 10:
		cout << 365 - ((28 + (6 * 31) + (30 * 3)) - (31 - b)) << endl;break;
	case 12:
		cout << 365 - ((28 + (7 * 31) + (30 * 4)) - (31 - b)) << endl;break;
	case 4:
		cout << 365 - (28 + (2 * 31) + 30 - (30 - b)) << endl; break;
	case 6:
		cout << 365 - (28 + (3 * 31) + (2 * 30) - (30 - b)) << endl; break;
	case 9:
		cout << 365 - (28 + (5 * 31) + (3 * 30) - (30 - b)) << endl; break;
	case 11:
		cout << 365 - (28 + (6 * 31) + (4 * 30) - (30 - b)) << endl; break;
	case 2:
		if (b < 29) {
			cout << 365 - (28 + 31 - (28 - b)) << endl; break;
		}
		else {
			cout << "Ошибка" << endl; break;
		}
	default:
		cout << "Ошибка" << endl; break;
	}

	return 0;
}



