#include<iostream>
#include<fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include<string>
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

bool is_get()
{
	size_t realsize;
	char* value = new char[5];
	getenv_s(&realsize, value, 5, "REQUEST_METHOD");
	bool res = !_strcmpi(value, "GET");
	delete[] value;
	return res;
}

size_t get_content_length()
{
	size_t realsize;
	char* value = new char[11];
	getenv_s(&realsize, value, 11, "CONTENT_LENGTH");
	size_t size;
	if (!realsize) size = 0;
	else sscanf_s(value, "%d", &size);
	delete[] value;
	return size;
}


void get_form_data(char*& data)
{
	delete[] data;
	if (is_get())
	{
		size_t realsize;
		char* value = new char[65536];
		getenv_s(&realsize, value, 65536, "QUERY_STRING");
		data = new char[realsize + 1];
		strcpy_s(data, realsize + 1, value);
		delete[] value;
	}
	else
	{
		size_t buf_size = get_content_length();
		data = new char[buf_size + 1];
		fread_s(
			data,
			buf_size + 1,
			sizeof(char),
			buf_size,
			stdin
		);
		data[buf_size] = 0;
	}
}

void str_decode(char*& dec_str, const char* enc_str)
{
	char* res = new char[strlen(enc_str) + 1];
	int i = 0, j = 0;
	while (enc_str[i])
	{
		if (enc_str[i] == '+')
		{
			res[j] = ' ';
		}
		else
		{
			if (enc_str[i] == '%')
			{
				char ch[3] = { enc_str[i + 1], enc_str[i + 2], 0 };
				int c;
				sscanf_s(ch, "%X", &c);
				res[j] = c;
				i += 2;
			}
			else
			{
				res[j] = enc_str[i];
			}
		}
		i++;
		j++;
	}
	res[j] = 0;
	size_t len = strlen(res) + 1;
	delete[] dec_str;
	dec_str = new char[len];
	strcpy_s(dec_str, len, res);
	delete[] res;
}

void get_param_value(char*& value, const char* param_name, const char* data)
{
	delete[] value;
	value = nullptr;
	char* str = _strdup(data);
	char* tmp = str;
	char* cont;
	while (char* part = strtok_s(tmp, "&", &cont))
	{
		tmp = nullptr;
		char* val;
		char* key = strtok_s(part, "=", &val);
		if (!_strcmpi(param_name, key))
		{
			str_decode(value, val);
			delete[] str;
			return;
		}
	}
	delete[] str;
	value = new char[1];
	value[0] = 0;
}


void show_footer() {
	cout << "&copy; Альбина Каримова";
}
void show_header() {
	cout << "Задание №3: Списки";
}
void show_content() {
	setlocale(LC_ALL, "Rus");
	elem* list = nullptr;
	cout << "<form method='get' action='Third.cgi'>";
	cout << "Введите размер списка: <input type='text' name='size' maxlength='50' size='50'><br>";
	cout << "Введите элементы списка через пробел: <input type='text' name='list' maxlength='50' size='50'><br>";
	cout << "<input type='submit' value='Отправить'>";
	cout << "</form>";

	char* data = nullptr;
	get_form_data(data);

	if (data && strlen(data) > 0)
	{
		char* value = nullptr;
		get_param_value(value, "size", data);
		cout << "<div>" <<"Size of list: "<< value << "</div>";
		get_param_value(value, "list", data);
		cout << "<div>" <<"Elements of list: "<< value << "</div>";

		const char* s = value;
		char* s_copy = new char[strlen(s) + 1];
		strcpy_s(s_copy, strlen(s) + 1, s);
		char* context;
		char* temp = s_copy;
		while (char* part = strtok_s(temp, " ", &context)) {
			int a;
			sscanf_s(part, "%d", &a);
			add(list, a);
			temp = nullptr;
		}
		cout << "List with unique values: ";
		unique(list);
		show_list(list);
	}
	delete[] data;
}
void show_menu() {
	ifstream f("Zadaniya");
	if (f.is_open()) {
		auto sz = 1024;
		auto buf = new char[sz];
		while (!f.eof()) {
			f.getline(buf, sz);
			char* name;
			char* addrr = strtok_s(buf, " ", &name);
			cout << "<div>"
				"<a href='" << addrr << "'>" <<
				name << "</a>"
				"</div>";
		}
	}
	f.close();
}
void main() {
	cout << "Content-type: text/html; charset=Windows-1251\n\n";
	ifstream f("_Profil");
	if (f.is_open()) {
		auto sz = 65536;
		auto buf = new char[sz];
		while (!f.eof()) {
			f.getline(buf, sz);
			if (strcmp(buf, "<!--#content#-->") == 0) {
				show_content();
			}
			else if (strcmp(buf, "<!--#menu#-->") == 0) {
				show_menu();
			}
			else if (strcmp(buf, "<!--#header#-->") == 0) {
				show_header();
			}
			else if (strcmp(buf, "<!--#footer#-->") == 0) {
				show_footer();
			}
			cout << buf;
		}
		delete[] buf;
		f.close();
	}
	else {
		cout << "Не удалось открыть страницу";
	}
}
