#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

using namespace std;

class Rectangle {
private:
    double x1, y1; // координаты левого нижнего угла
    double x2, y2; // координаты правого верхнего угла

public:
    // Конструкторы
    Rectangle();
    Rectangle(double x1, double y1, double x2, double y2);

    // Методы для получения параметров прямоугольника
    double getX1() const noexcept;
    double getY1() const noexcept;
    double getX2() const noexcept;
    double getY2() const noexcept;

    // Методы для вычисления площади и периметра
    double calculateArea() const noexcept;
    double calculatePerimeter() const noexcept;

    // Методы для перемещения, изменения размеров и сравнения
    void move(double dx, double dy);
    void resize(double dw, double dh);
    bool operator==(const Rectangle& other) const noexcept;
    bool operator<(const Rectangle& other) const noexcept;

    // Метод для получения прямоугольника пересечения
    Rectangle getIntersection(const Rectangle& other) const;

    // Метод для объединения двух прямоугольников
    Rectangle getUnion(const Rectangle& other) const;

    // Перегрузка операций ввода/вывода
    friend istream& operator>>(istream& in, Rectangle& rectangle);
    friend ostream& operator<<(ostream& out, const Rectangle& rectangle);

    // Метод преобразования в строку
    string toString() const;

};

#endif // RECTANGLE_H