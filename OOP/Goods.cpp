#include <Windows.h>
#include <iostream>
#include <stdexcept>
#include <iomanip> // Добавляем для setprecision
#include <sstream> // Добавляем для ostringstream
#include <cassert>

#pragma pack(1)

/*
* 1.	Создать класс Goods (товар). В классе должны быть представлены поля: наименование товара, цена товара, количество единиц товара, процент скидки. Реализовать методы, изменения цены товара, изменения количества товара (увеличения и уменьшения), вычисления стоимости товара, вычисление скидки и вычисление стоимости со скидкой. Реализовать методы сравнения по цене. 
*/

using namespace std;

class Goods {
private:
    string name; // наименование товара
    double price; // цена товара
    int count; // количество единиц товара
    double discount; // процент скидки
public:
    // Конструктор с параметрами
    Goods(const string& name, double price, int count, double discount) : name(name), price(price), count(count), discount(discount) {
        if (price < 0 || count < 0 || discount < 0 || discount > 100) {
            throw invalid_argument("Некорректные данные!");
        }
    }

    // Геттеры
    string GetName() const noexcept {
        return name;
    }

    double GetPrice() const noexcept {
        return price;
    }

    int GetCount() const noexcept {
        return count;
    }

    double GetDiscount() const noexcept {
        return discount;
    }

    // Сеттеры
    void SetName(const string& newName) {
        name = newName;
    }

    void SetPrice(double newPrice) {
        price = newPrice;
    }

    void SetCount(int newCount) {
        count = newCount;
    }

    void SetDiscount(double newDiscount) {
        discount = newDiscount;
    }

    // Метод изменения цены товара
    void changePrice(double delta) {
        SetPrice(price + delta);
    }

    // Метод изменения количества товара
    void changeCount(int delta) {
        SetCount(count + delta);
    }

    // Метод подсчета стоимости товара без скидки
    double CalculateCost() const {
        return (price * count);
    }

    // Метод для вычисления скидки
    double CalculateDiscount() const {
        return (price * count * discount) / 100.0;
    }

    // Метод стоимости товара со скидкой
    double CalculateCostWithDiscount() const {
        return (CalculateCost() - CalculateDiscount());
    }

    // Методы сравнения товаров по цене
    bool operator<(const Goods& other) const {
        return price < other.price;
    }

    bool operator>(const Goods& other) const {
        return price > other.price;
    }

    bool operator==(const Goods& other) const {
        return price == other.price;
    }

    // Метод преобразования в строку
    string toString() const {
        ostringstream result;
        result << name << "\n";

        // Устанавливаем желаемое количество знаков после запятой (2)
        result << fixed << setprecision(2) << price << "\n";
        result << count << "\n";
        result << fixed << setprecision(2) << discount << "\n";

        return result.str();
    }
};

// Метод ввода с клавиатуры
Goods Read() {
    string name;
    double price;
    int count;
    double discount;
    cout << "\nВведите наименование товара: ";
    cin >> name;
    cout << "Введите цену товара (р): ";
    cin >> price;
    cout << "Введите количество товара (шт): ";
    cin >> count;
    cout << "Введите скидку товара (%): ";
    cin >> discount;
    Goods goods{name, price, count, discount};
    return goods;
}

void DisplayCost(const Goods& item) noexcept {
    cout << endl;
    cout << item.GetName() << endl;
    cout << "Цена без скидки: " << item.CalculateCost() << " р." << endl;
    cout << "Цена со скидкой: " << item.CalculateCostWithDiscount() << " р." << endl;
    cout << "Скидка составила: " << item.CalculateDiscount() << " р." << endl;
}

// Метод вывода на экран
void Display(const Goods& item) noexcept {
    cout << endl;
    cout << item.toString();
    DisplayCost(item);
    cout << "\n";
}

int main() {
    SetConsoleOutputCP(1251);
    cout << "Яхьяев Данис ДИНРБ-21/2" << endl;
    cout << "Вариант 1" << endl;
    cout << "==========================" << endl;

    try {
        // Создаем второй объект с помощью конструктора с параметрами
        Goods item1("Item1", 20000.0, 15, 12.5);
        Display(item1); // Используем метод Display

        // Проверка с использованием assert
        assert(item1.GetName() == "Item1");
        assert(item1.GetPrice() == 20000.0);
        assert(item1.GetCount() == 15);
        assert(item1.GetDiscount() == 12.5);

        // Проверка методов вычисления стоимости и скидки:
        // Проверка метода CalculateCost
        assert(item1.CalculateCost() == 300000.0);

        // Проверка метода CalculateDiscount
        assert(item1.CalculateDiscount() == 37500.0);

        // Проверка метода CalculateCostWithDiscount
        assert(item1.CalculateCostWithDiscount() == 262500.0);


        Goods item2 = Read();
        Display(item2); // Используем метод Display

        if (item1 < item2) {
            cout << "Товар 1 дешевле товара 2." << endl;
        }
        else if (item1 > item2) {
            cout << "Товар 1 дороже товара 2." << endl;
        }
        else if (item1 == item2) {
            cout << "Товары стоят одинаково." << endl;
        }


    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
