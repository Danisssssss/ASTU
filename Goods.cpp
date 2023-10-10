#include "Goods.h"
#include <iostream>
#include <stdexcept>
#include <Windows.h>
#include <iomanip> // Добавляем для setprecision
#include <sstream> // Добавляем для ostringstream

using namespace std;

Goods::Goods() : name(""), price(0), count(0), discount(0.0) {}

// Конструктор с параметрами
Goods::Goods(const std::string& name, double price, int count, double discount)
	: name(name), price(price), count(count), discount(discount) {
	if (price < 0 || count < 0 || discount < 0) {
		throw std::invalid_argument("Некорректные данные!");
	}
}

// Метод инициализации
void Goods::Init(const string& name, double price, int count, double discount) {
	if (price < 0 || count < 0 || discount < 0) { // проверка на корректность
		throw invalid_argument("Некорректные данные!");
	}
	this->name = name;
	this->price = price;
	this->count = count;
	this->discount = discount;
}

// Геттеры
string Goods::GetName() const {
	return name;
}

double Goods::GetPrice() const {
	return price;
}

int Goods::GetCount() const {
	return count;
}

double Goods::GetDiscount() const {
	return discount;
}

// Сеттеры
void Goods::SetName(const string& newName) {
	name = newName;
}

void Goods::SetPrice(double newPrice) {
	if (newPrice < 0.0) {
		throw invalid_argument("Цена не может быть отрицательной!");
	}
	price = newPrice;
}

void Goods::SetCount(int newCount) {
	if (newCount < 0) {
		throw invalid_argument("Количество не может быть отрицательным!");
	}
	count = newCount;
}

void Goods::SetDiscount(double newDiscount) {
	if (newDiscount < 0.0 || newDiscount > 100.0) {
		throw invalid_argument("Скидка должна быть в диапазоне от 0 до 100!");
	}
	discount = newDiscount;
}

// Метод изменения цены товара
void Goods::changePrice(double delta) {
	SetPrice(price + delta);
}

// Метод изменения количества товара
void Goods::changeCount(int delta) {
	SetCount(count + delta);
}

// Метод подсчета стоимости товара без скидки
double Goods::CalculateCost() const {
	return (price * count);
}

// Метод для вычисления скидки
double Goods::CalculateDiscount() const {
	return (price * count * discount) / 100.0;
}

// Метод стоимости товара со скидкой
double Goods::CalculateCostWithDiscount() const {
	return (CalculateCost() - CalculateDiscount());
}

// Метод сравнения товаров по цене
bool Goods::operator<(const Goods& other) const {
	return price < other.price;
}

bool Goods::operator>(const Goods& other) const {
	return price > other.price;
}

bool Goods::operator==(const Goods& other) const {
	return price == other.price;
}

// Метод преобразования в строку
string Goods::toString() const {
	ostringstream result;
	result << "Наименование товара: " << name << "\n";

	// Устанавливаем желаемое количество знаков после запятой (2)
	result << "Цена товара: " << fixed << setprecision(2) << price << " р.\n";
	result << "Количество товара: " << count << " шт.\n";
	result << "Скидка товара: " << fixed << setprecision(2) << discount << " %\n";

	return result.str();
}

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
	Goods goods;
	goods.SetName(name);
	goods.SetPrice(price);
	goods.SetCount(count);
	goods.SetDiscount(discount);
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
}

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Яхьяев Данис ДИНРБ-21/2" << endl;
	cout << "Вариант 1" << endl;
	cout << "==========================" << endl;
	try {
		// Создаем объект класса Goods и инициализируем его различными способами

		Goods item1; // Используем конструктор по умолчанию
		item1.Init("Товар 1", 100.0, 5, 10.0); // Инициализируем методом Init
		item1.SetPrice(120.0); // Изменяем цену с помощью сеттера
		item1.changeCount(3); // Изменяем количество с помощью метода changeCount

		// Создаем второй объект с помощью конструктора с параметрами
		Goods item2("Товар 2", 150.0, 8, 5.0);

		Display(item1); // Используем метод Display
		Display(item2);

		if (item1 < item2) {
			cout << "Товар 1 дешевле товара 2." << endl;
		}
		else if (item1 > item2) {
			cout << "Товар 1 дороже товара 2." << endl;
		}
		else if (item1 == item2) {
			cout << "Товары стоят одинаково." << endl;
		}

		Goods item3;
		item3 = Read();
		Display(item3);
	}
	catch (const invalid_argument& e) {
		cout << "Ошибка: " << e.what() << endl;
	}

	return 0;
}
