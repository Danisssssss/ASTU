#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    cout << "Фамилия разработчика: Яхьяев Данис" << endl;
    cout << "Номер практического занятия: Лабораторная работа №3-4" << endl;
    cout << "Номер варианта: №18 Вычислить (a*c - a*b) / (b^2 - c^2) + (b^2 + a*b) / (3*a^2 - 3*a*b)" << endl;
    cout << "=========================" << endl;
    // Вычислить: Y = d - b - a + c
    // -- Тестовые значения-- 
    // для a = 2, b = 4, c = 3 ожидается ответ -2
    // для a = 3, b = 5, c = 4 ожидается ответ -2
    // для a = 7, b = 4, c = 5 ожидается ответ 0
    // для a = 2, b = 5, c = 1 ожидается ответ -1
    // для a = -4, b = -5, c = -2 ожидается ответ -3

    int chisl1 = 0;
    int zn1 = 0;
    int chisl2 = 0;
    int zn2 = 0;
    int resa = 0;
    int resc = 0;

    int a2, b2, c2, ac, ab;
    int a, b, c;
    cout << "Введите значения a, b и c: ";
    cin >> a >> b >> c;

    // Расчет необходимых промежуточных значений
    __asm {
        // a^2
        mov eax, a; // a
        imul eax, eax; // a ^ 2
        mov a2, eax; // 

        // b^2
        mov eax, b; // b
        imul eax, eax; // b ^ 2
        mov b2, eax; // 

        // c^2
        mov eax, c; // c
        imul eax, eax; // c ^ 2
        mov c2, eax; // 

        // ac
        mov eax, a; // a
        imul eax, c; // a * c
        mov ac, eax; // 

        mov eax, a; // a
        imul eax, b; // a * b
        mov ab, eax; // 

        // Вычисление числителя первой дроби
        mov eax, ac; // ac
        sub eax, ab; // ac - ab (числитель)
        mov chisl1, eax; //

        // Вычисление знаменателя первой дроби
        mov eax, b2; //  b^2
        sub eax, c2; // b ^ 2 - c ^ 2 (знаменатель)
        mov zn1, eax; // 

        // Вычисление числителя второй дроби
        mov eax, b2; // b^2
        add eax, ab; // b ^ 2 + ab(числитель)
        mov chisl2, eax; // 

        // Вычисление знаменателя второй дроби
        mov eax, a2; // a^2
        imul eax, 3; // 3*a^2
        mov ebx, ab; // ab
        imul ebx, 3; // 3 * ab
        sub eax, ebx; // 3*a^2 - 3*ab
        mov zn2, eax; // 

        // Вычисление результата
        mov eax, chisl1;
        cdq; // Расширяем eax до edx:eax для деления
        idiv zn1; // Делим числитель первой дроби на знаменатель
        mov ebx, eax;

        mov eax, chisl2; //
        cdq;
        idiv zn2;
        add eax, ebx;
        mov resa, eax;
    }

    cout << "Проверка на Assembler:" << endl;
    cout << "Числитель первой дроби chisl1 = " << chisl1 << endl;
    cout << "Знаменатель первой дроби zn1 = " << zn1 << endl;
    cout << "Числитель второй дроби chisl2 = " << chisl2 << endl;
    cout << "Знаменатель второй дроби zn2 = " << zn2 << endl;
    cout << "Результат res = " << resa << "\n\n";

    resc = (a * c - a * b) / (b * b - c * c) + (b * b + a * b) / (3 * a * a - 3 * a * b);
    cout << "Проверка на C++:" << endl;
    chisl1 = a * c - a * b;
    chisl2 = b * b + a * b;
    zn1 = b * b - c * c;
    zn2 = 3 * a * a - 3 * a * b;
    cout << "Проверка на C++:" << endl;
    cout << "Числитель первой дроби chisl1 = " << chisl1 << endl;
    cout << "Знаменатель первой дроби zn1 = " << zn1 << endl;
    cout << "Числитель второй дроби chisl2 = " << chisl2 << endl;
    cout << "Знаменатель второй дроби zn2 = " << zn2 << endl;
    cout << "Результат res = " << resa << "\n\n";
    cout << "(" << a << "*" << c << "-" << a << "*" << b << ")/(" << b << "^2-" << c << "^2) + (" << b << "^2+" << a << "*" << b << ")/( 3*" << a << "^2-3" << "*" << a << "*" << b << ")=" << resc << endl;

    return 0;
}
