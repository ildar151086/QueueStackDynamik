#include "PrintClass.h"

PrintClass::PrintClass() {
    sizeBoss = 0;
    sizefrend = 0;
    sizeOther = 0;
    boss = nullptr;
    frend = nullptr;
    other = nullptr;
}


int *PrintClass::pushPriority(int *queue, int &sizeQueue,int comand) {
    // ���� � ������� ��� ������ �� �������
    if (queue == nullptr) {
        // ���� ���� ��� ������ �� ������ �� ������� �������
        queue = new int[++sizeQueue];
        *queue = comand;
        return queue;
    }

    int* temp = new int[sizeQueue + 1];
    for (int i = 0; i < sizeQueue; i++) {
        // ����������������� ������ �������
        *(temp + i) = *(queue + i);
    }
    // ��������� ����� �������
    *(temp + sizeQueue) = comand;

    queue = temp;
    sizeQueue++;
    return queue;
}


// ��������� � ������� �� ������ � ����������� �� ����������
void PrintClass::Push(int PrintClassComand, int priority) {
    switch (priority)
    {
    case BOSS:
        boss  = pushPriority(boss, sizeBoss, PrintClassComand);
        break;
    case FREND:
        frend = pushPriority(frend, sizefrend, PrintClassComand);
        break;
    case OTHER:
        other = pushPriority(other, sizeOther, PrintClassComand);
        break;
    default:
        cout << "��������� �������� ���������� �����������" << endl;
        break;
    }
}

int* PrintClass::popPriorityStack(int* stack, int &sizeQueue, string str) {
    int* temp;
    if (sizeQueue != 0) {
        cout << "���������� ������� " << str << " " << *(stack + sizeQueue - 1) << endl;
        temp = new int[sizeQueue - 1];
        for (int i = 0; i < sizeQueue; i++) {
            *(temp + i) = *(stack + i);
        }
        sizeQueue--;
        stack = temp;
    }
    return stack;
}

int* PrintClass::popPriorityQueue(int* queue, int& sizeQueue, string str) {
    int* temp;
    if (sizeQueue != 0) {
        cout << "���������� ������� " << str << " " << *(queue) << endl;
        temp = new int[sizeQueue - 1];
        for (int i = 0; i < sizeQueue; i++) {
            *(temp + i) = *(queue + i + 1);
        }
        sizeQueue--;
        queue = temp;
    }
    return queue;
}

void PrintClass::pop() {
    if (sizeBoss != 0) {
        //boss = popPriorityStack(boss, sizeBoss, "����");
        boss = popPriorityQueue(boss, sizeBoss, "����");
    } 
    else if (sizefrend != 0) {
        //frend = popPriorityStack(frend, sizefrend, "����");
        frend = popPriorityQueue(frend, sizefrend, "����");
    }
    else if (sizeOther != 0) {
        //other = popPriorityStack(other, sizeOther, "������");
        other = popPriorityQueue(other, sizeOther, "������");
    }
}

void PrintClass::showPriority(const int *queue, int sizeQueue, string str) {
    cout << str;
    for (int i = 0; i < sizeQueue; i++) {
        cout << *(queue + i) << " ";
    }
    cout << endl;
}

void PrintClass::show() {
    showPriority(boss,   sizeBoss, "������� ���� ");
    showPriority(frend, sizefrend, "������� ���� ");
    showPriority(other, sizeOther, "������� ������ ");
}

bool PrintClass::inEmty() {
    if (sizeBoss != 0 || sizefrend != 0 || sizeOther != 0) {
        return 1;
    }
    return 0;
}

PrintClass::~PrintClass() {
    if (boss != nullptr) {
        delete boss;
    }
    if (frend != nullptr) {
        delete frend;
    }
    if (other != nullptr) {
        delete other;
    }
}