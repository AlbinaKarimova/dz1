#include<iostream>
#include<fstream>
using namespace std;
void show_footer() {
	cout << "&copy; Альбина Каримова";
}
void show_header() {
	cout << "Задание №2: Очередь";
}
void show_content() {
	cout << "<p>#include &#60iostream&#62;</p>";
	cout << "#include &#60string&#62;";
	cout << "<p>#include &#60fstream&#62;</p>";
	cout << "#include &#60string.h&#62;";
	cout << "<p>using namespace std;</p>";
	 cout << "struct man {";
	cout << "<p>char name[50];</p>";
	cout << "int age;";
	cout << "<p>char work[50];</p>";
	cout << "int salary;";
	cout << "<p>char goal[50];</p>";
	cout << "};";
	 cout << "<p>struct elem {</p>";
	cout << "man m; ";
	cout << "<p>elem* next = nullptr;</p>";
	cout << " };";
	 cout << "<p>struct queue {</p>";
	cout << " elem* head = nullptr;";
	cout << "<p>elem* tail = nullptr;</p>";
	cout << "size_t length = 0; ";
	cout << "<p>};</p>";
	 cout << " inline man create_elem(const char* name,int age,const char* work, int salary, const char* goal) {";
	cout << "<p>man m;</p>";
	cout << " strcpy_s(m.name, name);";
	cout << "<p>m.age = age;</p>";
	cout << "strcpy_s(m.work, work); ";
	cout << "<p>m.salary = salary;</p>";
	cout << "strcpy_s(m.goal, goal); ";
	cout << "<p>return m;</p>";
	cout << "} ";
	 cout << "<p>void enqueue(queue& queue, const char* name,int age, const char* work, int salary, const char* goal) {</p>";
	cout << " man newm = create_elem(name,age,work,salary,goal);";
	cout << "<p>elem* newel = new elem;</p>";
	cout << "newel->m = newm; ";
	cout << "<p>if (!queue.tail) {</p>";
	cout << " queue.head = queue.tail = newel;";
	cout << "<p>}</p>";
	cout << "else { ";
	cout << "<p>queue.tail->next = newel;</p>";
	cout << "queue.tail = newel; ";
	cout << "<p>}</p>";
	cout << "queue.length++;";
	cout << "<p>}</p>";
	 cout << "bool dequeue(queue& queue, man& m) {";
	cout << "<p>if (!queue.head) return false;</p>";
	cout << "m = queue.head->m;";
	cout << "<p>elem* rem = queue.head;</p>";
	cout << "queue.head = queue.head->next;";
	cout << "<p>delete rem;</p>";
	cout << "if (!queue.head) queue.tail = nullptr;";
	cout << "<p>queue.length--;</p>";
	cout << "return true;";
	cout << "<p>}</p>";
	 cout << "void clear(queue& queue) {";
	cout << "<p>while (queue.head) {</p>";
	cout << "elem* rem = queue.head;";
	cout << "<p>queue.head = queue.head->next;</p>";
	cout << "delete rem;";
	cout << "<p>}</p>";
	cout << "queue.length = 0;";
	cout << "<p>queue.tail = nullptr;</p>";
	cout << "}";
	 cout << "<p>void load_data(const char* filename, queue& kredit, queue& vklad) {</p>";
	cout << "ifstream f(filename);";
	cout << "<p>if (f.is_open()) {</p>";
	cout << "while (!f.eof()) {";
	cout << "<p>char* man = new char[300];</p>";
	cout << "f.getline(man, 300);";
	cout << "<p>char* name = new char[50];</p>";
	cout << "char* goal = new char[50];";
	cout << "<p>int age;</p>";
	cout << "char* work = new char[50];";
	cout << "<p>int salary;</p>";
	cout << "sscanf_s(man, \"%49[^0-9] %d %49[^0-9] %d %49[^0-9]\", name, 50,&age,work,50,&salary, goal, 50);";
	cout << "<p>int l = strlen(goal);</p>";
	cout << "if (goal[l - 1] == 'д') {";
	cout << "<p>enqueue(vklad, name,age,work,salary,goal);</p>";
	cout << "}";
	cout << "<p>else if (goal[l - 1] == 'т') {</p>";
	cout << "enqueue(kredit, name,age,work,salary,goal);";
	cout << "<p>}</p>";
	cout << "}";
	cout << "<p>f.close();</p>";
	cout << "}";
	cout << "<p>}</p>";
	 cout << "void show_data(queue& q) {";
	 cout << "<p>int i = 0;</p>";
	 cout << "while (q.length > 0) {";
	 cout << "<p>man m;</p>";
	cout << "if (dequeue(q, m)) {";
	cout << "<p>cout << ++i << \")\" << m.name <<\" Возраст: \" << m.age <<\" Место работы : \"<< m.work<<\" Доход : \"<< m.salary << \" Цель : \" << m.goal;</p>";
	cout << "<p>cout<< endl ;</p>";
	cout << "}";
	cout << "<p>}</p>";
	cout << "}";
	 cout << "<p>void main() {</p>";
	cout << "setlocale(LC_ALL, \"rus\");";
	cout << "<p>queue kredit;</p>";
	cout << "queue vklad;";
	cout << "<p>load_data(\"data.txt\", kredit, vklad);</p>";
	cout << "cout << \"Люди, взявшие кредит : \n\";";
	cout << "<p>cout<< endl; </p>";
	cout << "show_data(kredit);";
	cout << "<p>cout<< endl; </p>";
	cout << "cout << \"Лица, взявшие вклад : \n\";";
	cout << "<p>cout<< endl; </p>";
	cout << "show_data(vklad);";
	cout << "<p>}</p>";
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
		cout << "Не удалось вывести страницу";
	}
}