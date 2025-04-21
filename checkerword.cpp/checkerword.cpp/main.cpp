#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("text.txt");
    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    map<string, int> wordCount;
    string word;
    while (file >> word) wordCount[word]++; // збільшує лічильник цього слова в мапі
    file.close();

    cout << "Введіть слово: ";
    cin >> word;
    cout << "Слово \"" << word << "\" зустрічається " << wordCount[word] << " раз(ів)." << endl;

    return 0;
}
