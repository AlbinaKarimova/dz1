#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;

struct man {
	char name[50];
	int age;
	char work[50];
	int salary;
	char goal[50];
};

struct elem {
	man m;
	elem* next = nullptr;
};

struct queue {
	elem* head = nullptr;
	elem* tail = nullptr;
	size_t length = 0;
};

inline man create_elem(const char* name,int age,const char* work, int salary, const char* goal) {
	man m;
	strcpy_s(m.name, name);
	m.age = age;
	strcpy_s(m.work, work);
	m.salary = salary;
	strcpy_s(m.goal, goal);
	return m;
}

void enqueue(queue& queue, const char* name,int age, const char* work, int salary, const char* goal) {
	man newm = create_elem(name,age,work,salary,goal);
	elem* newel = new elem;
	newel->m = newm;
	if (!queue.tail) {
		queue.head = queue.tail = newel;
	}
	else {
		queue.tail->next = newel;
		queue.tail = newel;
	}
	queue.length++;
}

bool dequeue(queue& queue, man& m) {
	if (!queue.head) return false;
	m = queue.head->m;
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

void load_data(const char* filename, queue& kredit, queue& vklad) {
	ifstream f(filename);
	if (f.is_open()) {
		while (!f.eof()) {
			char* man = new char[300];
			f.getline(man, 300);
			char* name = new char[50];
			char* goal = new char[50];
			int age;
			char* work = new char[50];
			int salary;
			sscanf_s(man, "%49[^0-9] %d %49[^0-9] %d %49[^0-9]", name, 50,&age,work,50,&salary, goal, 50);
			int l = strlen(goal);
			if (goal[l - 1] == 'д') {
				enqueue(vklad, name,age,work,salary,goal);
			}
			else if (goal[l - 1] == 'т') {
				enqueue(kredit, name,age,work,salary,goal);
			}
		}
		f.close();
	}
}

void show_data(queue& q) {
	int i = 0;
	while (q.length > 0) {
		man m;
		if (dequeue(q, m)) {
			cout << ++i << ")" << m.name <<" Возраст:" << m.age <<" Место работы:"<<m.work<< " Доход:"<<m.salary << " Цель : " << m.goal;
			cout << endl;
		}
	}
}

void main() {
	setlocale(LC_ALL, "rus");
	queue kredit;
	queue vklad;
	load_data("data.txt", kredit, vklad);
	cout << "Люди, взявшие кредит:";
	cout << endl;
	show_data(kredit);
	cout << endl;
	cout << "Лица, взявшие вклад:";
	cout << endl;
	show_data(vklad);
}