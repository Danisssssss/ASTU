#include "Rectangle.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        // Создание объектов класса Rectangle
        Rectangle rect1(0, 0, 5, 5);
        Rectangle rect2(2, 2, 8, 8);

        // Проверки с использованием assert
        assert(rect1.calculateArea() == 25.0);
        assert(rect2.calculatePerimeter() == 24.0);

        // Вывод параметров прямоугольников
        cout << "Прямоугольник 1: " << rect1 << endl;
        cout << "Прямоугольник 2: " << rect2 << endl;

        // Вычисление и вывод площади и периметра
        cout << "Площадь прямоугольника 1: " << rect1.calculateArea() << endl;
        cout << "Периметр прямоугольника 2: " << rect2.calculatePerimeter() << endl;

        // Перемещение и изменение размеров прямоугольника
        rect1.move(2, 3);
        rect2.resize(3, 2);

        // Проверки с использованием assert после изменений
        assert(rect1.getX1() == 2.0);
        assert(rect2.getY2() == 10.0);

        // Вывод измененных параметров
        cout << "Перемещенный прямоугольник 1: " << rect1 << endl;
        cout << "Измененный размер прямоугольника 2: " << rect2 << endl;

        // Сравнение прямоугольников
        if (rect1 == rect2) {
            cout << "Прямоугольники равны по площади." << endl;
        }
        else if (rect1 < rect2) {
            cout << "У прямоугольника 1 меньший периметр, чем у прямоугольника 2." << endl;
        }
        else {
            cout << "У прямоугольника 1 больший периметр, чем у прямоугольника 2." << endl;
        }

        // Получение прямоугольника пересечения
        Rectangle intersection = rect1.getIntersection(rect2);
        cout << "Прямоугольник пересечения: " << intersection << endl;

        // Получение объединения двух прямоугольников
        Rectangle unionRect = rect1.getUnion(rect2);
        cout << "Прямоугольник объединения: " << unionRect << endl;

    }
    catch (const exception& e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    return 0;
}
