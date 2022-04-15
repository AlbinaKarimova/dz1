#include<iostream>
#include<fstream>
using namespace std;
void show_footer() {
	cout << "&copy; Альбина Каримова";
}
void show_content() {
	cout << "Дополнительный текст на второй странице";
}
void show_header() {
	cout << "Вторая страничка";
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
			else if (strcmp(buf, "<!--#menu#-->")==0) {
				show_menu();
			}
			else if (strcmp(buf, "<!--#header#-->")==0) {
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
		cout << "Не удалось вывести страницу";
	}
}