#include "function.h"

// Початково завдань 0
TaskManager::TaskManager() {
    count = 0;
}

// Додаємо нове завдання в масив
void TaskManager::addTask(string text, int priority) {
    if (count < 100) {
        list[count].text = text;
        list[count].priority = priority;
        count++;
    }
    else {
        cout << "Список завдань повний\n";
    }
}

// Видаляємо перше завдання в списку
void TaskManager::completeTask() {
    if (count == 0) {
        cout << "Немає завдань для виконання\n";
        return;
    }

    cout << "Виконано: " << list[0].text << endl;

    // Зсуваємо все вліво
    for (int i = 1; i < count; i++) {
        list[i - 1] = list[i];
    }

    count--;
}

// Перевіряємо, чи номер завдання коректний (в межах від 0 до count - 1).
// Якщо ні — виводимо повідомлення і виходимо з функції.
// Інакше — встановлюємо новий пріоритет для вибраного завдання. count - лычильник завдань 

void TaskManager::setPriority(int index, int newPriority) {
    if (index < 0 || index >= count) {
        cout << "Невірний номер завдання\n";
        return;
    }

    list[index].priority = newPriority;
}

// Виводимо всі завдання
void TaskManager::showTasks() {
    if (count == 0) {
        cout << "Список завдань порожній\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ") " << list[i].text << " (Пріоритет: " << list[i].priority << ")\n";
    }
}
