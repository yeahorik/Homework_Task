#include <iostream>
#include <Windows.h>
#include <string>
#include <list>
using namespace std;

// ��������� ������ ��������
struct Task {
    string text;     // ����� ��������
    int priority;    // ��������
};

// ���� ��� ��������� ������� �������
class TaskManager {
private:
    Task list[100];  // ����� ������� (�� 100)
    int count;       // ʳ������ �������� �������

public:
    TaskManager(); // �����������
    void addTask(string text, int priority); // ������ ��������
    void completeTask();                     // �������� �����
    void setPriority(int index, int newPriority); // ������ ��������
    void showTasks();                        // ������� ������
};

