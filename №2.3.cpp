/*������������� ����� � ��� ��� ����������� �����,
�����, ��� ����� ���� ��������� ������ ����� (������� ������ ����� �����)
����� ������� �����, � ��������. ������� ��� ���� ������������� �����,
������ �� ������� ������ 10000. ����������� �������, ������� ��������� ����� ��������� �����*/
#include<iostream>
using namespace std;
int SUMd(int n) {
    int sum = 0;
    for (int i = 1;i < n;i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}
int main() {
    setlocale(LC_ALL, "Rus");
    for (int i = 1;i <= 10000;i++) {
        int m = SUMd(i);
        if (m <= i)
            continue;
        if (i == SUMd(m) && m <= 10000) {
            cout << "���� ������������� �����: {" <<i<<";"<<m<<"}"<< endl;
        }
    }
}