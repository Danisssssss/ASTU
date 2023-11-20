#include "Rectangle.h"
#include <string>

using namespace std;

// Конструкторы
Rectangle::Rectangle() : x1(0), y1(0), x2(0), y2(0) {}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {}

// Методы для получения параметров прямоугольника
double Rectangle::getX1() const noexcept {
    return x1;
}

double Rectangle::getY1() const noexcept {
    return y1;
}

double Rectangle::getX2() const noexcept {
    return x2;
}

double Rectangle::getY2() const noexcept {
    return y2;
}

// Методы для вычисления площади и периметра
double Rectangle::calculateArea() const noexcept {
    return (x2 - x1) * (y2 - y1);
}

double Rectangle::calculatePerimeter() const noexcept {
    return 2 * ((x2 - x1) + (y2 - y1));
}

// Методы для перемещения, изменения размеров и сравнения
void Rectangle::move(double dx, double dy) {
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
}

void Rectangle::resize(double dw, double dh) {
    x2 += dw;
    y2 += dh;
}

bool Rectangle::operator==(const Rectangle& other) const noexcept {
    return calculateArea() == other.calculateArea();
}

bool Rectangle::operator<(const Rectangle& other) const noexcept {
    return calculatePerimeter() < other.calculatePerimeter();
}

// Метод для получения прямоугольника пересечения
Rectangle Rectangle::getIntersection(const Rectangle& other) const {
    double intersectX1 = max(x1, other.x1);
    double intersectY1 = max(y1, other.y1);
    double intersectX2 = min(x2, other.x2);
    double intersectY2 = min(y2, other.y2);

    if (intersectX1 < intersectX2 && intersectY1 < intersectY2) {
        return Rectangle(intersectX1, intersectY1, intersectX2, intersectY2);
    }
    else {
        // Возвращаем пустой прямоугольник, если пересечения нет
        return Rectangle();
    }
}

// Метод для объединения двух прямоугольников
Rectangle Rectangle::getUnion(const Rectangle& other) const {
    double unionX1 = min(x1, other.x1);
    double unionY1 = min(y1, other.y1);
    double unionX2 = max(x2, other.x2);
    double unionY2 = max(y2, other.y2);

    return Rectangle(unionX1, unionY1, unionX2, unionY2);
}

// Перегрузка операций ввода/вывода
istream& operator>>(istream& in, Rectangle& rectangle) {
    in >> rectangle.x1 >> rectangle.y1 >> rectangle.x2 >> rectangle.y2;
    return in;
}

ostream& operator<<(ostream& out, const Rectangle& rectangle) {
    out << "Rectangle: (" << rectangle.x1 << ", " << rectangle.y1 << ") - ("
        << rectangle.x2 << ", " << rectangle.y2 << ")";
    return out;
}

// Метод преобразования в строку
string Rectangle::toString() const {
    return "(" + to_string(x1) + ", " + to_string(y1) + ") - ("
        + to_string(x2) + ", " + to_string(y2) + ")";
}
