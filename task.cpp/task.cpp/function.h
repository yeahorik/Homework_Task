#include <iostream>
#include <Windows.h>
#include <string>
#include <list>
using namespace std;

// Структура одного завдання
struct Task {
    string text;     // Текст завдання
    int priority;    // Пріоритет
};

// Клас для керування списком завдань
class TaskManager {
private:
    Task list[100];  // Масив завдань (до 100)
    int count;       // Кількість поточних завдань

public:
    TaskManager(); // Конструктор
    void addTask(string text, int priority); // Додати завдання
    void completeTask();                     // Виконати перше
    void setPriority(int index, int newPriority); // Змінити пріоритет
    void showTasks();                        // Вивести список
};

