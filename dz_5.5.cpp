
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
void count(char* s, char* word) {
    char* k;
    int i = 0;
    k = s;
    while (k = strstr(k, word)) {
        i++;
        k++;
    }
    cout << "Новое расширение = " << i;
}

int main() {
    setlocale(LC_ALL, "Rus");
    char word[256];
    cin.getline(word, 256);
    char s[256];
    cin.getline(s, 256);
    count(s, word);
    return 0;
}
