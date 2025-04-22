#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <chrono>
#include <Windows.h>

using namespace std;


struct person {
    string name;
    int ticket;
    bool attented = false;
};

int ticketNumber = 1;
queue<person> hospitalQueue;


void addToQueue() {
    string name;
    cout << "������ ��'� ��������: ";
    getline(cin, name);

    person newPerson{ name, ticketNumber++, false };
    hospitalQueue.push(newPerson);

    cout << "������� " << newPerson.name << " ������� �����: " << newPerson.ticket << "\n\n";
}


void callNext() {
    if (hospitalQueue.empty()) {
        cout << "����� �������!\n\n";
        return;
    }

    // ��������� ������� �������� � ����
    person current = hospitalQueue.front();
    cout << "����������� ����� " << current.ticket << " (" << current.name << ")\n";
    cout << "� ��� � 5 ������, ��� ��������� ENTER\n";

    string input;
    bool responded = false;

    // ���� ��� ���������� �����
    thread inputThread([&]() {
        getline(cin, input); // ������ ���������� ENTER
        responded = true;
        });


    for (int i = 0; i < 50; ++i) {
        if (responded) break;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    if (inputThread.joinable()) {
        inputThread.detach(); // ��������� ����, �� �� ����� �� �������
    }

    // ���� ������� ��������� ���� ����������
    if (responded) {
        cout << "������� " << current.name << " ��������� ����������.\n\n";
        hospitalQueue.pop(); // �������� ����� �������� � �����
    }
    else {
        cout << "������� �� �'������. ���������� �� ����������.\n\n";
        hospitalQueue.pop(); // �������� ��������, �� �� �'������

        // ��������, �� � ��������� �������
        if (!hospitalQueue.empty()) {
            callNext(); // ��������� ���������� ��������
        }
    }
}

// ����������� ������ ��������
void viewQueue() {
    if (hospitalQueue.empty()) {
        cout << "������ �������!\n\n";
        return;
    }

    cout << "������ �������� � ����:\n";
    queue<person> tempQueue = hospitalQueue; // ��������� ����� ��� ���������
    while (!tempQueue.empty()) {
        person current = tempQueue.front();
        cout << "�����: " << current.ticket << ", ��'�: " << current.name << "\n";
        tempQueue.pop();
    }
    cout << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        cout << "1. ������ �������� �� �����\n";
        cout << "2. ��������� ��������\n";
        cout << "3. ����������� ������ ��������\n";
        cout << "4. �����\n";
        cout << "����: ";

        string choice;
        getline(cin, choice);

        if (choice == "1") {
            addToQueue();
        }
        else if (choice == "2") {
            callNext();
        }
        else if (choice == "3") {
            viewQueue();
        }
        else if (choice == "4") {
            cout << "���������� ��������.\n";
            break;
        }
        else {
            cout << "������� ����! ��������� �� ���.\n\n";
        }
    }

    return 0;
}
