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

    int chisl1 = 0; // переменная для хранения числителя первой дроби, равного a*c - a*b
    int zn1 = 0; // переменная для хранения знаменателя первой дроби, равного b^2 - c^2
    int chisl2 = 0; // переменная для хранения числителя второй дроби, равного b^2 + a*b
    int zn2 = 0; // переменная для хранения знаменателя второй дроби, равного 3*a^2 - 3*a*b
    int resa = 0; // результат вычисления выражения на Ассемблере
    int resc = 0; // результат вычисления выражения на C++

    int a2, // переменная для хранения a^2
        b2, // переменная для хранения b^2
        c2, // переменная для хранения c^2
        ac, // переменная для хранения a*c
        ab; // переменная для хранения a*b
    int a, b, c;
    cout << "Введите значения a, b и c: ";
    cin >> a >> b >> c; // ввод значения а, b, c

    __asm {
        mov eax, a; // поместили а в регистр еах
        imul eax, eax; // значение регистра eax умножили на значение регистра eax 
		               // (т.е. a*a = a^2)
        mov a2, eax; // содержимое регистра eax занесли в ячейку a2 (a^2)
        mov eax, b; // поместили b в регистр еах
        imul eax, eax; // значение регистра eax умножили на значение регистра eax 
		               // (т.е. b*b = b^2)
        mov b2, eax; // содержимое регистра eax занесли в ячейку b2 (b^2)
        mov eax, c; // поместили c в регистр еах
        imul eax, eax; // значение регистра eax умножили на значение регистра eax 
		               // (т.е. c*c = c^2)
        mov c2, eax; // содержимое регистра eax занесли в ячейку c2 (c^2) 
        mov eax, a; // поместили а в регистр еах
        imul eax, c; // умножили содержимое регистра eax на c, получили a*c
        mov ac, eax; // содержимое регистра eax занесли в ячейку ac (a*c)
        mov eax, a; // поместили а в регистр еах
        imul eax, b; // умножили содержимое регистра eax на b, получили a*b
        mov ab, eax; // содержимое регистра eax занесли в ячейку ab (a*b) 
        mov eax, ac; // поместили в регистр eax содержимое ячейки ac
        sub eax, ab; // вычли из содержимого регистра eax содержимое ячейки ab
        mov chisl1, eax; // содержимое регистра eax занесли в ячейку chisl1 (числитель первой дроби)
        mov eax, b2; // поместили в регистр eax содержимое ячейки b2
        sub eax, c2; // вычли из содержимого регистра eax содержимое ячейки c2
        mov zn1, eax; // содержимое регистра eax занесли в ячейку zn1 (знаменатель первой дроби)
        mov eax, b2; // поместили в регистр eax содержимое ячейки b2
        add eax, ab; // eax := eax + значение переменной ab, получили b^2 + a*b
        mov chisl2, eax; // содержимое регистра eax занесли в ячейку chisl2 (числитель второй дроби)
        mov eax, a2; // поместили в регистр eax содержимое ячейки a2
        imul eax, 3; // умножили содержимое регистра eax на 3, получили 3*a^2
        mov ebx, ab; // поместили в регистр ebx содержимое ячейки ab
        imul ebx, 3; // умножили содержимое регистра ebx на 3, получили 3*a*b
        sub eax, ebx; // вычли из содержимого регистра eax содержимое регистра ebx
        mov zn2, eax; // содержимое регистра eax занесли в ячейку zn2 (знаменатель второй дроби)
        mov eax, chisl1; // поместили в регистр eax содержимое ячейки chisl1
        cdq; // преобразовали двойное слово в учетверённое
             // -- без этого происходит переполнение 
        idiv zn1; // edx:eax := eax:edx / zn1 с учётом знака
        mov ebx, eax; // содержимое регистра eax занесли в содержимое регистра ebx - первая дробь
        mov eax, chisl2; // поместили в регистр eax содержимое ячейки chisl2
        cdq; // преобразовали двойное слово в учетверённое
             // -- без этого происходит переполнение 
        idiv zn2; // edx:eax := eax:edx / zn2 с учётом знака
        add eax, ebx; // eax := eax + ebx, первая дробь + вторая дробь
        mov resa, eax; // содержимое регистра eax занесли в ячейку resa
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
    cout << "(" << a << "*" << c << "-" << a << "*" << b << ")/(" << b << "^2-" << c << "^2) + (" << b << "^2+" << a << "*" << b 
        << ")/( 3*" << a << "^2-3" << "*" << a << "*" << b << ")=" << resc << endl;

    return 0;
}
