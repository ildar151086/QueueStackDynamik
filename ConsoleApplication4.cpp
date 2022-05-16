/*
Разработать приложение, имитирующее пе-
чать принтера . Должны быть клиенты, посылающие
запросы на принтер, у каждого из которых есть свой
приоритет. Необходимо
сохранять статистику печати (пользователь, время). Предусмотреть вывод статистики на экран.
*/
#include <iostream>
#include "PrintClass.h"


using namespace std;


int main()
{
    setlocale(LC_ALL, "RUS");
    PrintClass print;

    for (int i = 0; i < 3; i++) {
        print.Push(i, BOSS);
    }
    for (int i = 0; i < 6; i++) {
        print.Push(i, FREND);
    }
    for (int i = 0; i < 10; i++) {
        print.Push(i, OTHER);
    }

    print.show();

    while (print.inEmty()) {
        print.pop();
    }
}