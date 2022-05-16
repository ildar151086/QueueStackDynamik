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
    // Если в оыереди нет команд то создаем
    if (queue == nullptr) {
        // Если нету еще команд на печать то создаем очередь
        queue = new int[++sizeQueue];
        *queue = comand;
        return queue;
    }

    int* temp = new int[sizeQueue + 1];
    for (int i = 0; i < sizeQueue; i++) {
        // Переприсываеввыем старые команды
        *(temp + i) = *(queue + i);
    }
    // Добавляем новую команду
    *(temp + sizeQueue) = comand;

    queue = temp;
    sizeQueue++;
    return queue;
}


// Добавляем в очередь на печать в зависимости от приоритета
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
        cout << "Введенное значение приоритета недопустимо" << endl;
        break;
    }
}

int* PrintClass::popPriorityStack(int* stack, int &sizeQueue, string str) {
    int* temp;
    if (sizeQueue != 0) {
        cout << "Отправлена команда " << str << " " << *(stack + sizeQueue - 1) << endl;
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
        cout << "Отправлена команда " << str << " " << *(queue) << endl;
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
        //boss = popPriorityStack(boss, sizeBoss, "босс");
        boss = popPriorityQueue(boss, sizeBoss, "босс");
    } 
    else if (sizefrend != 0) {
        //frend = popPriorityStack(frend, sizefrend, "друг");
        frend = popPriorityQueue(frend, sizefrend, "друг");
    }
    else if (sizeOther != 0) {
        //other = popPriorityStack(other, sizeOther, "другие");
        other = popPriorityQueue(other, sizeOther, "другие");
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
    showPriority(boss,   sizeBoss, "Очередь Босс ");
    showPriority(frend, sizefrend, "Очередь Друг ");
    showPriority(other, sizeOther, "Очередь Другое ");
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