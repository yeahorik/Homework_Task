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
        cout << "�� ������� ������� ����!" << endl;
        return 1;
    }

    map<string, int> wordCount;
    string word;
    while (file >> word) wordCount[word]++; // ������ �������� ����� ����� � ���
    file.close();

    cout << "������ �����: ";
    cin >> word;
    cout << "����� \"" << word << "\" ����������� " << wordCount[word] << " ���(��)." << endl;

    return 0;
}
