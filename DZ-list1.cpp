/*Написать программу, в которой реализовать функции добавления и
вставки элементов в односвязный список, так, чтобы в списке 
оставались только уникальные значения.*/

#include<iostream>
using namespace std;

struct elem {
	int a;
	elem* next = nullptr;
};

void add(elem*& first, int data) {
	elem* newel = new elem;
	newel->a = data;
	if (first) {
		elem* curr = first;
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = newel;
	}
	else {
		first = newel;
	}
}

const int* get(const elem* first, int pos) {
	if (pos < 0 || !first) return nullptr;
	elem* curr = (elem*)first;
	int p = 0;
	while (p < pos && curr) {
		curr = curr->next;
		p++;
	}
	if (curr) return &curr->a;
	return nullptr;
}

int count(const elem* first) {
	int cnt = 0;
	elem* curr = (elem*)first;
	while (curr) {
		cnt++;
		curr = curr->next;
	}
	return cnt;
}

bool remove(elem*& first, int pos) {
	if (!first || pos < 0) return false;
	if (!pos) {
		elem* rem = first;
		first = first->next;
		delete rem;
		return true;
	}

	int p = 0;
	elem* curr = first;
	while (p < pos - 1 && curr->next) {
		curr = curr->next;
		p++;
	}
	if (curr->next) {
		elem* rem = curr->next;
		curr->next = curr->next->next;
		delete rem;
		return true;
	}
	return false;
}

void clear(elem*& first) {
	while (first) {
		elem* rem = first;
		first = first->next;
		delete rem;
	}
}

void show_list(const elem* list) {
	elem* curr = (elem*)list;
	if (!curr) cout << "Empty list!" << endl;
	else while (curr) {
		cout << curr->a << (curr->next ? " " : "\n");
		curr = curr->next;
	}
}

void unique(elem*& list) {
	int cnt = count(list);
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			auto val1 = *get(list, i);
			auto val2 = *get(list, j);
			if (i != j) {
				if (val1 == val2) {
					remove(list, j);
					cnt--;
				}
			}
		}
	}
}

void load_list(elem*& list) {
	int n;
	cin >> n;//введите размер списка
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;//введите элементы списка через пробел
		add(list, a);
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	elem* list = nullptr;
	load_list(list);
	cout << endl;
	cout << "Список с уникальными значениями: \n";
	unique(list);
    show_list(list);
}