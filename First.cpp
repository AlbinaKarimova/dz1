#include<iostream>
#include<fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include<string>
using namespace std;
struct elem
{
	char value;
	elem* next = nullptr;
};

void push(elem*& top, char value) {
	auto* newel = new elem;
	newel->value = value;
	if (top) newel->next = top;
	top = newel;
}

bool pop(elem*& top, char& value) {
	if (!top) return false;
	value = top->value;
	auto* rem = top;
	top = top->next;
	delete rem;
	return true;
}
const char* peek(const elem* top) {
	if (!top) return nullptr;
	return &top->value;
}

void clear(elem*& top) {
	while (top) {
		auto* rem = top;
		top = top->next;
		delete rem;
	}
}

void check_stack(elem*& top, char*& s) {
	int len = strlen(s);
	int k = 0, n = 0, t = 0, v = 0;
	for (int i = 0; i < len + 1; i++) {
		if (s[i] == '(') {
			k = i;
			push(top, s[i]);
		}
		else if (s[i] == ')') {
			if (s[k] == '(') pop(top, s[i]);
			else break;
		}
		if (s[i] == '{') {
			t = i;
			push(top, s[i]);
		}
		else if (s[i] == '}') {
			if (s[t] == '{') pop(top, s[i]);
			else break;
		}
		if (s[i] == '<') {
			v = i;
			push(top, s[i]);
		}
		else if (s[i] == '>') {
			if (s[v] == '<') pop(top, s[i]);
			else break;
		}
		if (s[i] == '[') {
			n = i;
			push(top, s[i]);
		}
		else if (s[i] == ']') {
			if (s[n] == '[') pop(top, s[i]);
			else break;
		}
	}
	if (peek(top) == nullptr) cout << "Выражение верно!";
	else cout << "В выражении есть ошибка!";
}

void show_stack(elem* top) {
	if (!top) cout << "Стек пуст!" << endl;
	else {
		auto* curr = top;
		while (curr) {
			auto val = peek(curr);
			cout << *val << (curr->next ? ' ' : '\n');
			curr = curr->next;
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

void show_footer(){
	cout << "&copy; Альбина Каримова";
}

void show_content() {

	char* data = nullptr;
	elem* stack = nullptr;
	string s1;
	cout << "<form method='get' action='First.cgi'>";
	cout << "Введите свое выражение: <input type='text' name='imya' maxlength='50' size='50'><br>";
	cout << "<input type='submit' value='Отправить'>";
	cout << "</form>";
	
	get_form_data(data);

	if (data && strlen(data) > 0)
	{
		char* value = nullptr;
		get_param_value(value, "imya", data);
		cout << "<div>" << value << "</div>";
		check_stack(stack, value);
		cout << '\n' << "Текущий стек: " << endl;
		show_stack(stack);
		clear(stack);
	}
	delete[] data;
}
void show_header() {
	cout << "Задание №1: Стек";
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
    setlocale(LC_ALL, "rus");
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
	else  cout << "Не удалось вывести страницу";
}
