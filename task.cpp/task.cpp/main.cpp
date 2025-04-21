#include "function.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TaskManager tm;
    int choice;

    while (true) {
        cout << "\n����:\n";
        cout << "1. ������ ��������\n";
        cout << "2. �������� ����� ��������\n";
        cout << "3. ������ �������� ��������\n";
        cout << "4. �������� �� ��������\n";
        cout << "5. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        if (choice == 1) {
            string text;
            int prio;
            cout << "������ ����� ��������: ";
            cin.ignore();
            getline(cin, text);
            cout << "������ ��������: ";
            cin >> prio;
            tm.addTask(text, prio);
        }
        else if (choice == 2) {
            tm.completeTask();
        }
        else if (choice == 3) {
            int index, newPrio;
            tm.showTasks();
            cout << "������ ����� ��������: ";
            cin >> index;
            cout << "����� ��������: ";
            cin >> newPrio;
            tm.setPriority(index - 1, newPrio);
        }
        else if (choice == 4) {
            tm.showTasks();
        }
        else if (choice == 5) {
            cout << "�������� ���������!\n";
            break;
        }
        else {
            cout << "������� ����\n";
        }
    }

    return 0;
}
