#pragma once

#ifndef GOODS_H
#define GOODS_H

#include <string>

using namespace std;

class Goods {
public:
    Goods(); // Конструктор по умолчанию
    Goods(const string& name, double price, int count, double discount); // Конструктор с параметрами

    void Init(const string& name, double price, int count, double discount);

    // Геттеры
    string GetName() const;
    double GetPrice() const;
    int GetCount() const;
    double GetDiscount() const;

    // Сеттеры
    void SetName(const string& newName);
    void SetPrice(double newPrice);
    void SetCount(int newCount);
    void SetDiscount(double newDiscount);

    // Методы для работы с объектом Goods
    void changePrice(double delta);
    void changeCount(int delta);
    double CalculateCost() const;
    double CalculateDiscount() const;
    double CalculateCostWithDiscount() const;
    bool operator<(const Goods& other) const;
    bool operator>(const Goods& other) const;
    bool operator==(const Goods& other) const;
    string toString() const;

private:
    string name; // наименование товара
    double price; // цена товара
    int count; // количество единиц товара
    double discount; // процент скидки
};

#endif
