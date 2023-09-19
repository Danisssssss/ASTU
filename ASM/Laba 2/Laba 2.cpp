#include <iostream> // подключаем библиотеку с функциями ввода-вывода (printf, system)
using namespace std; // используем пространство имен std

int main() { // обычный код на C++
    setlocale(LC_ALL, "RU"); // Подключение русского языка
    // Вывод информации о разработчике и номере варианта
    cout << "Фамилия разработчика: Яхьяев Данис" << endl;
    cout << "Номер практического занятия: Лабораторная работа №3-4" << endl;
    cout << "Номер варианта: №18 Вычислить (a*c - a*b) / (b^2 - c^2) + (b^2 + a*b) / (3*a^2 - 3*a*b)" << endl;
    cout << "=========================" << endl;
    
    int a, b, c;
    cout << "Введите значения a, b и c: ";
    cin >> a >> b >> c;

    int chisl1, zn1, chisl2, zn2, resa, resc;

    // Вычисление числителей и знаменателей дробей
    __asm {
        // Вычисление числителя первой дроби: ac - ab
        mov eax, a
        imul eax, c
        mov ebx, a
        imul ebx, b
        sub eax, ebx
        mov chisl1, eax

        // Вычисление знаменателя первой дроби: b^2 - c^2
        mov eax, b
        imul eax, b
        mov ebx, c
        imul ebx, c
        sub eax, ebx
        mov zn1, eax

        // Вычисление числителя второй дроби: b^2 + ab
        mov eax, b
        imul eax, b
        mov ebx, a
        imul ebx, b
        add eax, ebx
        mov chisl2, eax

        // Вычисление знаменателя второй дроби: 3a^2 - 3ab
        mov eax, 3
        imul eax, a
        imul ebx, b
        sub eax, ebx
        mov zn2, eax
    }

    // Вычисление и вывод результата на C++
    resc = (chisl1 / zn1) + (chisl2 / zn2);
    cout << "Результат вычисления на C++: " << resc << endl;

    // Вычисление и вывод результата на ассемблере
    __asm {
        mov eax, chisl1
        cdq
        idiv zn1
        mov resa, eax
    }
    cout << "Результат вычисления на ассемблере: " << resa << endl;

    return 0; // Завершение программы и возвращение нулевого значения
}
