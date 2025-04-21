#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

bool isBracketsCorrect(const string& s) {
    string stack; // �����, stack � �� ��������� ����, �� �� ������� ����� ������ �����, ��� ���� ���������, �� ���� ��������� "���������".
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack += ch; 
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) return false;
            char last = stack.back();
            stack.pop_back();
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string input;
    cout << "������ ����� � �������: ";
    cin >> input;

    if (isBracketsCorrect(input)) {
        cout << "����� ���������� ���������.\n";
    }
    else {
        cout << "����� ���������� �����������.\n";
    }

    return 0;
}
