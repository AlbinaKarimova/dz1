#include<iostream>
#include<string>
using namespace std;
struct elem
{
    char value;
    elem* next = nullptr;
};

void push(elem*& top, char value) {
    auto* newel = new elem;
    newel->value=value;
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

void check_stack(elem*& top, string& s) {
    int len = s.length();
    int k = 0, n = 0,t = 0,v = 0;
    for (int i = 0; i <len+1; i++) {
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

void main() {
    setlocale(LC_ALL, "rus");
    elem* stack = nullptr;
    string s1 ="([{<}>])";
    string s2 = "([{<>}])";
    cout << "Выражение 1:" << s1 << endl;
    check_stack(stack, s1);
    cout <<'\n' << "Текущий стек: " << endl;
    show_stack(stack);
    clear(stack);
    cout << endl;
    cout << "Выражение 2:" << s2 << endl;
    check_stack(stack, s2);
    cout <<'\n' << "Текущий стек: " << endl;
    show_stack(stack);
}
