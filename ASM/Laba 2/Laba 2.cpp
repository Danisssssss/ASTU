#include <iostream> // подключаем библиотеку с функциями ввода-вывода (printf, system)
using namespace std; // используем пространство имен std

int main() { // обычный код на C++
    setlocale(LC_ALL, "RU"); // Подключение русского языка
    // Вывод информации о разработчике и номере варианта
    cout << "Фамилия разработчика: Яхьяев Данис" << endl;
    cout << "Номер практического занятия: Лабораторная работа №3-4" << endl;
    cout << "Номер варианта: №18 Вычислить (a*c - a*b) / (b^2 - c^2) + (b^2 + a*b) / (3*a^2 - 3*a*b)" << endl;
    cout << "=========================" << endl;
    // Вычислить: (ac - ab) / (b^2 - c^2) + (b^2 + ab) / (3a^2 - 3ab)
    // -- Тестовые значения-- 
    // для a = 1, b = 2, c = 3, ожидается ответ 4
    // для a = 5, b = 7, c = 9, ожидается ответ -2
    // для a = -4, b = 2, c = 7, ожидается ответ 4

    int chisl1 = 0; // переменная для хранения первого числителя дроби, равного ac - ab
    int zn1 = 0; // переменная для хранения первого знаменателя дроби, равного b^2 - c^2
    int chisl2 = 0; // переменная для хранения второго числителя дроби, равного b^2 + ab
    int zn2 = 0; // переменная для хранения второго знаменателя дроби, равного 3a^2 - 3ab
    int resa = 0; // результат вычисления выражения на Ассемблере
    int resc = 0; // результат вычисления выражения на C++

    int a2,
        b2,
        c2,
        ac,
        ab;

    int a, b, c; // Объявление переменных для хранения значений a, b и c
    cout << "Введите значения a, b и c: "; // Вывод сообщения на экран и ожидание ввода значений a, b и c
    cin >> a >> b >> c;

    // int result_cpp = d - b - a + c; // Вычисление выражения Y на C++ и сохранение результата в переменной result_cpp

    // cout << "Результат вычисления на C++: Y = " << d << " - " << b << " - " << a << " + " << c << " = " << result_cpp << endl; // Вывод результата вычисления на C++ на экран

    // Вставка ассемблерного кода для вычисления Y
    __asm {
        mov eax, a; // Загрузка значения переменной a в регистр eax
        mov ebx, b; // Загрузка значения переменной b в регистр ebx
        mov ecx, c; // Загрузка значения переменной c в регистр ecx

    }


    return 0; // Завершение программы и возвращение нулевого значения
}
