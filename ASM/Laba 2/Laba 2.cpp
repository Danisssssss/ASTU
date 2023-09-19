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
    // для a = , b = , c = , ожидается ответ
    // для a = , b = , c = , ожидается ответ
    // для a = , b = , c = , ожидается ответ

    int chisl1 = 0; // переменная для хранения первого числителя дроби, равного ac - ab
    int zn1 = 0; // переменная для хранения первого знаменателя дроби, равного b^2 - c^2
    int chisl2 = 0; // переменная для хранения второго числителя дроби, равного b^2 + ab
    int zn2 = 0; // переменная для хранения второго знаменателя дроби, равного 3a^2 - 3ab
    int resa = 0; // результат вычисления выражения на Ассемблере
    int resc = 0; // результат вычисления выражения на C++

    int a2,  // переменная для хранения a^2
        b2, // переменная для хранения b^2
        c2, // переменная для хранения c^2
        ac, // переменная для хранения a*c
        ab; // переменная для хранения a*b

    int a, b, c; // Объявление переменных для хранения значений a, b и c
    cout << "Введите значения a, b и c: "; // Вывод сообщения на экран и ожидание ввода значений a, b и c
    cin >> a >> b >> c;
    
    // Вставка ассемблерного кода для вычисления Y
    __asm {
        // Вычисление a^2, b^2 и c^2
        mov eax, a
        imul eax, a
        mov a2, eax
    
        mov ebx, b
        imul ebx, b
        mov b2, ebx
    
        mov ecx, c
        imul ecx, c
        mov c2, ecx
    
        // Вычисление a*c и a*b
        mov eax, a
        imul eax, c
        mov ac, eax
    
        mov ebx, a
        imul ebx, b
        mov ab, ebx
    
        // Вычисление числителя и знаменателя первой дроби: (ac - ab) / (b^2 - c^2)
        sub eax, ebx
        mov chisl1, eax
    
        sub b2, c2
        mov zn1, b2
    
        // Вычисление числителя и знаменателя второй дроби: (b^2 + ab) / (3a^2 - 3ab)
        add b2, ebx
        mov chisl2, b2
    
        mov edx, 3
        imul edx, a2
    
        mov ebx, 3
        imul ebx, ab
    
        sub edx, ebx
        mov zn2, edx
    
        // Вычисление итогового результата
        mov eax, chisl1
        imul eax, zn2
    
        mov ebx, chisl2
        imul ebx, zn1
    
        add eax, ebx
        mov resa, eax
    }

    // Вывод результата на экран
    cout << "Результат на ассемблере: " << resa << endl;


    return 0; // Завершение программы и возвращение нулевого значения
}
