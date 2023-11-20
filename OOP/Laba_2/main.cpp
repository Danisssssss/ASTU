#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    try {
        // �������� �������� ������ Rectangle
        Rectangle rect1(0, 0, 5, 5);
        Rectangle rect2(2, 2, 8, 8);

        // ����� ���������� ���������������
        cout << "������������� 1: " << rect1 << endl;
        cout << "������������� 2: " << rect2 << endl;

        // ���������� � ����� ������� � ���������
        cout << "������� �������������� 1: " << rect1.calculateArea() << endl;
        cout << "�������� �������������� 2: " << rect2.calculatePerimeter() << endl;

        // ����������� � ��������� �������� ��������������
        rect1.move(2, 3);
        rect2.resize(3, 2);

        // ����� ���������� ����������
        cout << "������������ ������������� 1: " << rect1 << endl;
        cout << "���������� ������ �������������� 2: " << rect2 << endl;

        // ��������� ���������������
        if (rect1 == rect2) {
            cout << "�������������� ����� �� �������." << endl;
        }
        else if (rect1 < rect2) {
            cout << "� �������������� 1 ������� ��������, ��� � �������������� 2." << endl;
        }
        else {
            cout << "� �������������� 1 ������� ��������, ��� � �������������� 2." << endl;
        }

        // ��������� �������������� �����������
        Rectangle intersection = rect1.getIntersection(rect2);
        cout << "������������� �����������: " << intersection << endl;

        // ��������� ����������� ���� ���������������
        Rectangle unionRect = rect1.getUnion(rect2);
        cout << "������������� �����������: " << unionRect << endl;

    }
    catch (const exception& e) {
        cerr << "����������: " << e.what() << endl;
    }

    return 0;
}
