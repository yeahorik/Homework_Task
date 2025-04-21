#include "function.h"

// ��������� ������� 0
TaskManager::TaskManager() {
    count = 0;
}

// ������ ���� �������� � �����
void TaskManager::addTask(string text, int priority) {
    if (count < 100) {
        list[count].text = text;
        list[count].priority = priority;
        count++;
    }
    else {
        cout << "������ ������� ������\n";
    }
}

// ��������� ����� �������� � ������
void TaskManager::completeTask() {
    if (count == 0) {
        cout << "���� ������� ��� ���������\n";
        return;
    }

    cout << "��������: " << list[0].text << endl;

    // ������� ��� ����
    for (int i = 1; i < count; i++) {
        list[i - 1] = list[i];
    }

    count--;
}

// ����������, �� ����� �������� ��������� (� ����� �� 0 �� count - 1).
// ���� � � �������� ����������� � �������� � �������.
// ������ � ������������ ����� �������� ��� ��������� ��������. count - ��������� ������� 

void TaskManager::setPriority(int index, int newPriority) {
    if (index < 0 || index >= count) {
        cout << "������� ����� ��������\n";
        return;
    }

    list[index].priority = newPriority;
}

// �������� �� ��������
void TaskManager::showTasks() {
    if (count == 0) {
        cout << "������ ������� �������\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ") " << list[i].text << " (��������: " << list[i].priority << ")\n";
    }
}
