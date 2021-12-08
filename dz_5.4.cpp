/*Напишите функцию, которая изменяет в имени файла расширение на заданное (например, на «.bak»).
Функция принимает два параметра: имя файла и нужно расширение. Учтите, что в исходном имени расширение может быть пустым.*/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
void change_r(char* s, const char* r) {
    const char* s1 = strtok(s, ".");
    while (s1 != NULL) {
        strtok(NULL, ".");
        break;
    }
    strcat(s, r);
    cout << "Новая строка : " << s;
}
int main() {
    const char* r = ".bac";
    char s[256];
    cin >> s;
    change_r(s, r);
    return 0;
}