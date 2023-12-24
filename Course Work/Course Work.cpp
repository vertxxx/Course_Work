#include <iostream>
#include "Lab1.cpp"
#include "Lab2.cpp"
#include "Lab3.cpp"
#include "Lab4.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    system("cls");
    int lab;
    cout << "Веберите номер практической работы, которую хотите выбрать(1 - 4):\n\n"
        << "0 - Выход из программы.\n\n";
    cin >> lab;
    system("cls");
    switch (lab)
    {
    case 1:
        menu1();
        main();
        break;
    case 2:
        menu2();
        main();
        break;
    case 3:
        menu3();
        main();
        break;
    case 4:
        menu4();
        main();
        break;
    case 0:
        exit(1);
        break;
    default:
        main();
        break;
    }
    return 0;
}