#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

bool isBracketsCorrect(const string& s) {
    string stack; // Тобто, stack — це тимчасове місце, де ми тримаємо тільки відкриті дужки, щоб потім перевірити, чи вони правильно "закрилися".
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
    cout << "Введіть рядок з дужками: ";
    cin >> input;

    if (isBracketsCorrect(input)) {
        cout << "Дужки розставлені правильно.\n";
    }
    else {
        cout << "Дужки розставлені неправильно.\n";
    }

    return 0;
}
