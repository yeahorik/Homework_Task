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
    cout << "Введіть ім'я пацієнта: ";
    getline(cin, name);

    person newPerson{ name, ticketNumber++, false };
    hospitalQueue.push(newPerson);

    cout << "Пацієнт " << newPerson.name << " отримав номер: " << newPerson.ticket << "\n\n";
}


void callNext() {
    if (hospitalQueue.empty()) {
        cout << "Черга порожня!\n\n";
        return;
    }

    // Викликаємо першого пацієнта в черзі
    person current = hospitalQueue.front();
    cout << "Викликається номер " << current.ticket << " (" << current.name << ")\n";
    cout << "У вас є 5 секунд, щоб натиснути ENTER\n";

    string input;
    bool responded = false;

    // Потік для зчитування вводу
    thread inputThread([&]() {
        getline(cin, input); // Чекаємо натискання ENTER
        responded = true;
        });


    for (int i = 0; i < 50; ++i) {
        if (responded) break;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    if (inputThread.joinable()) {
        inputThread.detach(); // Завершуємо потік, бо він більше не потрібен
    }

    // Якщо пацієнт підтвердив свою присутність
    if (responded) {
        cout << "Пацієнт " << current.name << " підтвердив присутність.\n\n";
        hospitalQueue.pop(); // Забираємо цього пацієнта з черги
    }
    else {
        cout << "Пацієнт не з'явився. Переходимо до наступного.\n\n";
        hospitalQueue.pop(); // Забираємо пацієнта, що не з'явився

        // Перевірка, чи є наступний пацієнт
        if (!hospitalQueue.empty()) {
            callNext(); // Викликаємо наступного пацієнта
        }
    }
}

// Переглянути список пацієнтів
void viewQueue() {
    if (hospitalQueue.empty()) {
        cout << "Список порожній!\n\n";
        return;
    }

    cout << "Список пацієнтів у черзі:\n";
    queue<person> tempQueue = hospitalQueue; // Тимчасова черга для перегляду
    while (!tempQueue.empty()) {
        person current = tempQueue.front();
        cout << "Номер: " << current.ticket << ", Ім'я: " << current.name << "\n";
        tempQueue.pop();
    }
    cout << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        cout << "1. Додати пацієнта до черги\n";
        cout << "2. Викликати пацієнта\n";
        cout << "3. Переглянути список пацієнтів\n";
        cout << "4. Вийти\n";
        cout << "Вибір: ";

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
            cout << "Завершення програми.\n";
            break;
        }
        else {
            cout << "Невірний вибір! Спробуйте ще раз.\n\n";
        }
    }

    return 0;
}
