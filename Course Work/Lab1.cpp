#include <iostream>
#include <conio.h>

using namespace std;

void sizes()
{
    setlocale(LC_ALL, "RU");
    cout << "Задание №1" << "\n\n";
    cout << "Размер int: " << sizeof(int) << "\n"
        << "Размер short int: " << sizeof(short int) << "\n"
        << "Размер long int: " << sizeof(long int) << "\n"
        << "Размер float: " << sizeof(float) << "\n"
        << "Размер double: " << sizeof(double) << "\n"
        << "Размер long double: " << sizeof(long double) << "\n"
        << "Размер char: " << sizeof(char) << "\n"
        << "Размер bool: " << sizeof(bool) << "\n\n"
        << "Нажмите любую клавишу, чтобы вернуться в главное меню";
    _getch();
    system("cls");
}

void integerToBinary()
{
    cout << "Задание №2: " << "\n\n";
    int value;
    cout << "Введите число типа int:\n\n";
    cin >> value;
    int order = sizeof(value) * 8;
    unsigned int mask = 1 << order - 1;
    for (int i = 0; i < order; i++) {
        putchar((value & mask) ? '1' : '0');
        mask >>= 1;

        if (i % 8 == 0)
            putchar(' ');
    }
    cout << "\n\nНажмите любую клавишу, чтобы вернуться в главное меню";
    _getch();
    system("cls");
}

void floatToBinary()
{
    cout << "\n\n" << "Задание №3" << "\n\n";
    union
    {
        int intA;
        float floatB;
    };
    cout << "Введите число типа float:\n\n";
    cin >> floatB;
    int order = sizeof(float) * 8;
    unsigned int mask = 1 << order - 1;
    for (int i = 0; i < order; i++) {
        putchar((intA & mask) ? '1' : '0');
        mask >>= 1;
        if (i == 0 || i == 8)
            putchar(' ');
    }
    cout << "\n\nНажмите любую клавишу, чтобы вернуться в главное меню";
    _getch();
    system("cls");
}

void doubleToBinary()
{
    cout << "\n\n" << "Задание №4" << "\n\n";
    union
    {
        int doubleM[2];
        double doubleD;
    };
    int order = sizeof(double) * 8;
    unsigned int mask = 1 << order - 1;
    cout << "\n\nВведите число типа double:\n\n";
    cin >> doubleD;
    for (int i = 1; i >= 0; i--)
    {
        for (int j = 0; j < order / 2; j++)
        {
            putchar((doubleM[i] & mask) ? '1' : '0');
            mask >>= 1;
            if (i == 1 && (j == 0 || j == 11))
                putchar(' ');
        }
        mask = 1 << order - 1;
    }
    cout << "\n\nНажмите любую клавишу, чтобы вернуться в главное меню";
    _getch();
    system("cls");
}

void menu()
{
    setlocale(LC_ALL, "RU");
    int mainMenu;
    {
        cout << "Какой пункт вы хотите выбрать?\n"
            << "1 - Cколько байтов на вашем компьютере отводится под различные типы данных\n"
            << "2 - Двоичное представление в памяти числа типа int\n"
            << "3 - Двоичное представление в памяти числа типа float\n"
            << "4 - Двоичное представление в памяти числа типа double\n"
            << "5 - Выход\n\n";
    }
    cin >> mainMenu;

    switch (mainMenu)
    {
    case 1:
        sizes();
        menu();
        break;
    case 2:
        integerToBinary();
        menu();
        break;
    case 3:
        floatToBinary();
        menu();
        break;
    case 4:
        doubleToBinary();
        menu();
        break;
    case 5:
        break;
    default:
        cout << "Ошибка! Попробуйте снова";
        _getch();
        system("cls");
        menu();
        break;

    }
}

void menu1()
{
    menu();
}