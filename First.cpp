#include<iostream>
#include<fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
void show_footer() {
	cout << "&copy; Альбина Каримова";
}

void show_content() {
    cout << "<p>#include &#60iostream&#62;</p>";
    cout << "#include &#60string&#62;";
    cout << "<p>using namespace std;</p>";
    cout << "struct elem{";
    cout << "<p>char value;</p>";
    cout << "elem* next = nullptr;";
    cout << "<p>};</p>";
    cout << "void push(elem * &top, char value) {";
    cout << "<p>auto* newel = new elem;</p>";
    cout << "newel->value = value;";
    cout << "<p>if (top) newel->next = top;</p>";
    cout << "top = newel;";
    cout << "<p>}</p>";  
    cout << "bool pop(elem * &top, char& value) {";
    cout << "<p>if (!top) return false;</p>";
    cout << "value = top->value;";
    cout << "<p>auto* rem = top;</p>";
    cout << "top = top->next;";
    cout << "<p>delete rem;</p>";
    cout << "return true;";
    cout << "<p>}</p>";
    cout << "const char* peek(const elem * top) {";
    cout << "<p>if (!top) return nullptr;</p>";
    cout << "return &top->value;";
    cout << "<p>}</p>";
    cout << "void clear(elem * &top) {";
    cout << "<p>while (top) {</p>";
    cout << "auto* rem = top;";
    cout << "<p>top = top->next;</p>";
    cout << "delete rem;";
    cout << "<p>}</p>";
    cout << "}";
    cout << "<p>void check_stack(elem * &top, string & s) {</p>";
    cout << "int len = s.length();";
    cout << "<p>int k = 0, n = 0, t = 0, v = 0;</p>";
    cout << "for (int i = 0; i < len + 1; i++) {";
    cout << "<p>if (s[i] == '(') {</p>";
    cout << "k = i;";
    cout << "<p>push(top, s[i]);</p>";
    cout << "}";
    cout << "<p>else if (s[i] == ')') {</p>";
    cout << "if (s[k] == '(') pop(top, s[i]);";
    cout << "<p>else break;</p>";
    cout << "}";
    cout << "<p>if (s[i] == '{') {</p>";
    cout << "t = i;";
    cout << "<p>push(top, s[i]);</p>";
    cout << "}";
    cout << "<p>else if (s[i] == '}') {</p>";
    cout << "if (s[t] == '{') pop(top, s[i]);";
    cout << "<p>else break;</p>";
    cout << "}";
    cout << "<p>if (s[i] == '<') {</p>";
    cout << "v = i;";
    cout << "<p>push(top, s[i]);</p>";
    cout << "}";
    cout << "<p>else if (s[i] == '>') {</p>";
    cout << "if (s[v] == '<') pop(top, s[i]);";
    cout << "<p>else break;</p>";
    cout << "}";
    cout << "<p>if (s[i] == '[') {</p>";
    cout << "n = i;";
    cout << "<p>push(top, s[i]);</p>";
    cout << "}";
    cout << "<p>else if (s[i] == ']') {</p>";
    cout << "if (s[n] == '[') pop(top, s[i]);";
    cout << "<p>else break;</p>";
    cout << "}";
    cout << "<p>}</p>";
    cout << "if (peek(top) == nullptr) cout<<\"Выражение верное!\";";
    cout << "<p>else cout << \"В выражении есть ошибка!\";</p>";
    cout << "}";
    cout << "<p>void show_stack(elem * top) {</p>";
    cout << "if (!top) cout <<\" Стек пуст!\" << endl;";
    cout << "<p>else {</p>";
    cout << "auto * curr = top;";
    cout << "<p>while (curr) {</p>";
    cout << "auto val = peek(curr);";
    cout << "<p>cout << *val << (curr->next ? ' ' : '\n');</p>";
    cout << "curr = curr->next;";
    cout << "<p>}</p>";
    cout << "}";
    cout << "<p>}</p>";
    cout << "void main() {";
    cout << "<p>setlocale(LC_ALL,\"Russian\");</p>";
    cout << "elem* stack = nullptr;";
    cout << "<p>string s1 = \"([{ < } > ])\";</p>";
    cout << "string s2 = \"([{<>}])\";";
    cout << "cout << \"Выражение 1:\" << s1 << endl;";
    cout << "<p>check_stack(stack, s1);</p>";
    cout << "cout<< \"Текущий стек :\"  << endl;";
    cout << "<p>show_stack(stack);</p>";
    cout << "clear(stack);";
    cout << "<p>cout << endl;</p>";
    cout << "cout <<\" Выражение 2:\" << s2 << endl;";
    cout << "<p>check_stack(stack, s2);</p>";
    cout << "cout << \"Текущий стек : \" << endl;";
    cout << "<p>show_stack(stack);</p>";
    cout << "}";
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
