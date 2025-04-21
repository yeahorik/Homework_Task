#include "function.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TaskManager tm;
    int choice;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Додати завдання\n";
        cout << "2. Виконати перше завдання\n";
        cout << "3. Змінити пріоритет завдання\n";
        cout << "4. Показати всі завдання\n";
        cout << "5. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            string text;
            int prio;
            cout << "Введіть текст завдання: ";
            cin.ignore();
            getline(cin, text);
            cout << "Введіть пріоритет: ";
            cin >> prio;
            tm.addTask(text, prio);
        }
        else if (choice == 2) {
            tm.completeTask();
        }
        else if (choice == 3) {
            int index, newPrio;
            tm.showTasks();
            cout << "Введіть номер завдання: ";
            cin >> index;
            cout << "Новий пріоритет: ";
            cin >> newPrio;
            tm.setPriority(index - 1, newPrio);
        }
        else if (choice == 4) {
            tm.showTasks();
        }
        else if (choice == 5) {
            cout << "Програма завершена!\n";
            break;
        }
        else {
            cout << "Невірний вибір\n";
        }
    }

    return 0;
}
