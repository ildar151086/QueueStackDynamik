#include <iostream>
using namespace std;


enum PRIORITY {
    BOSS,
    FREND,
    OTHER
};

class PrintClass {
    // ���������� ���������� �� ������ � ������� ����������
    int sizeBoss;
    int sizefrend;
    int sizeOther;
    // ������ �� ������� � �����������
    int* boss;
    int* frend;
    int* other;

    int *pushPriority(int *queue, int& sizeQueue, int comand);
    void showPriority(const int* queue, int sizeQueue, string str);
    int* popPriorityStack(int* queue, int& sizeQueue, string str);
    int* popPriorityQueue(int* queue, int& sizeQueue, string str);
public:
    PrintClass();

    void Push(int PrintClassComand, int priority);
    void pop();
    void show();
    bool inEmty();

    ~PrintClass();
};


