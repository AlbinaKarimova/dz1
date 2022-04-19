#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;

struct man {
	string name;
	int age;
	string gender;
	string work;
	string salary;
	string goal;
};

struct elem {
	man value;
	elem* next = nullptr;
};

struct queue {
	elem* head = nullptr;
	elem* tail = nullptr;
	size_t length = 0;
};
void enqueue(queue& q, man m) {
	elem* newel = new elem;
	newel->value = m;
	if (!q.tail) {
		q.head = q.tail = newel;
	}
	else {
		q.tail->next = newel;
		q.tail = newel;
	}
	q.length++;
}

bool dequeue(queue& queue, man& m) {
	if (!queue.head) return false;
	m = queue.head->value;
	elem* rem = queue.head;
	queue.head = queue.head->next;
	delete rem;
	if (!queue.head) queue.tail = nullptr;
	queue.length--;
	return true;
}

void clear(queue& queue) {
	while (queue.head) {
		elem* rem = queue.head;
		queue.head = queue.head->next;
		delete rem;
	}
	queue.length = 0;
	queue.tail = nullptr;
}

int main() {
	setlocale(LC_ALL, "rus");
	queue kredit;
	queue vklad;
	ifstream f("data.txt");
	ofstream fi("vklad.txt");
	ofstream fio("kredit.txt");
	if (f.is_open() && fi.is_open() && fio.is_open()) {
		while (!f.eof()) {
			man m;
			f >> m.name >> m.gender >> m.age >> m.work >> m.salary >> m.goal;
			if (m.goal == "Вклад") {
				enqueue(vklad, m);
				fi << m.name << " " << m.gender << " " << m.age << " " << m.work << " " << m.salary << " " << m.goal << endl;

			}
			else if (m.goal == "Кредит") {
				enqueue(kredit, m);
				fio << m.name << " " << m.gender << " " << m.age << " " << m.work << " " << m.salary << " " << m.goal << endl;
			}
		}

	}
	else cout << "ERROR";
	f.close();
	fi.close();
	fio.close();
	cout << "Папка с людьми, взявшими кредит:";
	cout << endl;
	cout << "kredit.txt";
	cout << endl;
	cout << "Папка с людьми, взявшими вклад:";
	cout << endl;
	cout << "vklad.txt";
	return 0;
}
