#include <Windows.h>
#include <iostream>
#include <stdexcept>
#include <iomanip> // ��������� ��� setprecision
#include <sstream> // ��������� ��� ostringstream
#include <cassert>

#pragma pack(1)

/*
* 1.	������� ����� Goods (�����). � ������ ������ ���� ������������ ����: ������������ ������, ���� ������, ���������� ������ ������, ������� ������. ����������� ������, ��������� ���� ������, ��������� ���������� ������ (���������� � ����������), ���������� ��������� ������, ���������� ������ � ���������� ��������� �� �������. ����������� ������ ��������� �� ����.
*/

using namespace std;

class Goods {
private:
    string name; // ������������ ������
    double price; // ���� ������
    int count; // ���������� ������ ������
    double discount; // ������� ������
public:
    // ����� �������������
    void Init(const string& name, double price, int count, double discount) {
        if (price < 0 || count < 0 || discount < 0) { // �������� �� ������������
            throw invalid_argument("������������ ������!");
        }
        this->name = name;
        this->price = price;
        this->count = count;
        this->discount = discount;
    }

    // �������
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

    // �������
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

    // ����� ��������� ���� ������
    void changePrice(double delta) {
        SetPrice(price + delta);
    }

    // ����� ��������� ���������� ������
    void changeCount(int delta) {
        SetCount(count + delta);
    }

    // ����� �������� ��������� ������ ��� ������
    double CalculateCost() const {
        return (price * count);
    }

    // ����� ��� ���������� ������
    double CalculateDiscount() const {
        return (price * count * discount) / 100.0;
    }

    // ����� ��������� ������ �� �������
    double CalculateCostWithDiscount() const {
        return (CalculateCost() - CalculateDiscount());
    }

    // ������ ��������� ������� �� ����
    bool operator<(const Goods& other) const {
        return price < other.price;
    }

    bool operator>(const Goods& other) const {
        return price > other.price;
    }

    bool operator==(const Goods& other) const {
        return price == other.price;
    }

    // ����� �������������� � ������
    string toString() const {
        ostringstream result;
        result << name << "\n";

        // ������������� �������� ���������� ������ ����� ������� (2)
        result << fixed << setprecision(2) << price << "\n";
        result << count << "\n";
        result << fixed << setprecision(2) << discount << "\n";

        return result.str();
    }
};

// ����� ����� � ����������
Goods Read() {
    string name;
    double price;
    int count;
    double discount;
    cout << "\n������� ������������ ������: ";
    cin >> name;
    cout << "������� ���� ������ (�): ";
    cin >> price;
    cout << "������� ���������� ������ (��): ";
    cin >> count;
    cout << "������� ������ ������ (%): ";
    cin >> discount;
    Goods goods;
    goods.Init(name, price, count, discount);
    return goods;
}

void DisplayCost(const Goods& item) noexcept {
    cout << endl;
    cout << item.GetName() << endl;
    cout << "���� ��� ������: " << item.CalculateCost() << " �." << endl;
    cout << "���� �� �������: " << item.CalculateCostWithDiscount() << " �." << endl;
    cout << "������ ���������: " << item.CalculateDiscount() << " �." << endl;
}

// ����� ������ �� �����
void Display(const Goods& item) noexcept {
    cout << endl;
    cout << item.toString();
    DisplayCost(item);
    cout << "\n";
}

int main() {
    SetConsoleOutputCP(1251);
    cout << "������ ����� �����-21/2" << endl;
    cout << "������� 1" << endl;
    cout << "==========================" << endl;

    try {
        Goods item1;

        item1.Init("Item1", 20000.0, 15, 12.5); // �������������� ������� Init
        Display(item1); // ���������� ����� Display

        // �������� � �������������� assert
        assert(item1.GetName() == "Item1");
        assert(item1.GetPrice() == 20000.0);
        assert(item1.GetCount() == 15);
        assert(item1.GetDiscount() == 12.5);

        // �������� ������� ���������� ��������� � ������:
        // �������� ������ CalculateCost
        assert((item1.CalculateCost() - 300000.0) < 0.0001);

        // �������� ������ CalculateDiscount
        assert((item1.CalculateDiscount() - 37500.0) < 0.0001);

        // �������� ������ CalculateCostWithDiscount
        assert((item1.CalculateCostWithDiscount() - 262500.0) < 0.0001);



        // ������� ������ ������
        Goods item2;
        item2.Init("Item2", 25000.0, 10, 10.0);
        Display(item2); // ���������� ����� Display

        // �������� � �������������� assert
        assert(item2.GetName() == "Item2");
        assert(item2.GetPrice() == 25000.0);
        assert(item2.GetCount() == 10);
        assert(item2.GetDiscount() == 10.0);

        // �������� ������� ���������� ��������� � ������:
        // �������� ������ CalculateCost
        assert(item2.CalculateCost() == 250000.0);

        // �������� ������ CalculateDiscount
        assert(item2.CalculateDiscount() == 25000.0);

        // �������� ������ CalculateCostWithDiscount
        assert(item2.CalculateCostWithDiscount() == 225000.0);



        if (item1 < item2) {
            cout << "����� 1 ������� ������ 2." << endl;
        }
        else if (item1 > item2) {
            cout << "����� 1 ������ ������ 2." << endl;
        }
        else if (item1 == item2) {
            cout << "������ ����� ���������." << endl;
        }

        // �������� ���������� ���������
        assert(item1 < item2);
        assert(!(item1 > item2));
        assert(!(item1 == item2));


    }
    catch (const invalid_argument& e) {
        cout << "������: " << e.what() << endl;
    }

    return 0;
}
