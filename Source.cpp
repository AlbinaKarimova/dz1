//Загрузить из файла информацию об успеваемости студентов за последнюю сессию(в файле указаны фамилии, инициалы и средний балл).
//
//1. Сформировать дерево для поиска по фамилии или среднему баллу(по выбору пользователя).Построенное дерево вывести в виде таблицы.
//
//2. Вывести из дерева баллы всех студентов с фамилией на заданную букву.

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct student {
	string name;
	int mark;
};

struct tree {
	student m;
	tree* left = nullptr;
	tree* right = nullptr;
	string letter;
};

inline student create_elem(string name, int mark) {
	student m;
	m.name=name;
	m.mark = mark;
	return m;
}


void add_name(tree*& root, string new_name, int new_mark) {
	tree* newelem = new tree;
	student newm=create_elem(new_name, new_mark);
	newelem->m = newm;
	if (!root) {
		root = newelem;
		return;
	}
	if (root->m.name > new_name) {
		add_name(root->left, new_name,new_mark);
		return;
	}
	if (root->m.name < new_name) {
		add_name(root->right, new_name,new_mark);
		return;
	}
	if (root->m.name == new_name) {
		return;
	}
}

void add_mark(tree*& root, string new_name, int new_mark) {
	tree* newelem = new tree;
	student newm = create_elem(new_name, new_mark);
	newelem->m = newm;
	if (!root) {
		root = newelem;
		return;
	}
	if (root->m.mark > new_mark) {
		add_name(root->left, new_name, new_mark);
		return;
	}
	if (root->m.mark < new_mark) {
		add_name(root->right, new_name, new_mark);
		return;
	}
	if (root->m.mark == new_mark) {
		return;
	}
}

void show_correct(tree* root) {
	if (!root) return;
	if (root->left != nullptr) {
		show_correct(root->left);
	}
	cout << "|" << root->m.name << " " << root->m.mark << "|" << endl;
	if (root->right != nullptr) {
		show_correct(root->right);
	}
}

void load_data(const char* filename,tree*& root,int flag) {
	ifstream f(filename);
	if (f.is_open()) {
		while (!f.eof()) {
			student m;
			f >> m.name >> m.mark;
			if (flag == 1) {
				add_name(root, m.name, m.mark);
			}
			else if (flag == 2) {
				add_mark(root, m.name, m.mark);
			}
			else {
				cout << "Неверно введенный символ, внимательно прочитайте условие.";
				break;
			}
			cout << endl;
		}
	}
	else cout << "Error";
	f.close();
}

int _find_in_tree(tree* root, string name, int mark, char letter) {
	if (!root) return 0;
	if (letter == name[0]) {
		if (root->m.name == name) return root->m.mark;
		if (name < root->m.name)
			return _find_in_tree(root->left, name, mark, letter);
		return _find_in_tree(root->right, name, mark, letter);
	}
}

void search_in_tree(const char* filename, tree*& root, char letter) {
	ifstream f(filename);
	if (f.is_open()) {
		while (!f.eof()) {
			student m;
			f >> m.name >> m.mark;
			if (_find_in_tree(root, m.name, m.mark, letter) !=69)
			cout << _find_in_tree(root, m.name, m.mark, letter)<<" ";
		}
	}
	else cout << "Error";
	f.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
	tree* root = nullptr;

	//поиск по студентов по фамилии или среднему баллу
	cout << "Выберите сортировку дерева: по фамилии(введите 1) или по среднему баллу(введите 2)" << endl;
	int flag;
	cin >> flag;
	load_data("data.txt", root, flag);
	cout << endl;
	show_correct(root);
	cout << endl;

	//2. Вывести из дерева баллы всех студентов с фамилией на заданную букву.
	cout << "Баллы студентов с фамилией на букву И:" << endl;
	search_in_tree("data.txt", root, 'И');
	cout << endl;
	cout << "Баллы студентов с фамилией на букву Ш:" << endl;
	search_in_tree("data.txt", root, 'Ш');
	return 0;
}