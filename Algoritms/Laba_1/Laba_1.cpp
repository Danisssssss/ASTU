#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Структура для хранения элементов списка
struct Node {
    int type; // Тип элемента (1 - строка, 2 - массив чисел, 3 - массив строк, 4 - структура)
    string data_string;
    vector<int> data_int_array;
    vector<string> data_string_array;
    struct {
        int field1;
        int field2;
        string field3;
        string field4;
    } data_struct;
    Node* next; // Указатель на следующий элемент
};

// Функция для создания нового элемента списка
Node* CreateNode() {
    Node* newNode = new Node;
    cout << "Введите тип элемента (1 - строка, 2 - массив чисел, 3 - массив строк, 4 - структура): ";
    cin >> newNode->type;

    switch (newNode->type) {
    case 1:
        cout << "Введите строку: ";
        cin >> newNode->data_string;
        break;
    case 2:
        int num;
        cout << "Введите размер массива чисел: ";
        cin >> num;
        for (int i = 0; i < num; ++i) {
            int value;
            cout << "Введите число " << i + 1 << ": ";
            cin >> value;
            newNode->data_int_array.push_back(value);
        }
        break;
    case 3:
        int strNum;
        cout << "Введите размер массива строк: ";
        cin >> strNum;
        for (int i = 0; i < strNum; ++i) {
            string str;
            cout << "Введите строку " << i + 1 << ": ";
            cin >> str;
            newNode->data_string_array.push_back(str);
        }
        break;
    case 4:
        cout << "Введите два числовых поля: ";
        cin >> newNode->data_struct.field1 >> newNode->data_struct.field2;
        cout << "Введите два строковых поля: ";
        cin >> newNode->data_struct.field3 >> newNode->data_struct.field4;
        break;
    default:
        cout << "Неверный тип элемента." << endl;
        delete newNode;
        return nullptr;
    }

    newNode->next = nullptr;
    return newNode;
}

// Функция для добавления элемента в конец списка
void AddNodeToEnd(Node*& head, Node* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функция для вывода длины списка
int GetListLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// Функция для поиска элемента в списке
int SearchInList(Node* head, int searchType, const string& searchData) {
    int index = 0;
    Node* current = head;
    while (current != nullptr) {
        index++;
        switch (searchType) {
        case 1:
            if (current->type == 1 && current->data_string == searchData) {
                return index;
            }
            break;
        case 2:
            if (current->type == 2) {
                for (int num : current->data_int_array) {
                    if (num == stoi(searchData)) {
                        return index;
                    }
                }
            }
            break;
        case 3:
            if (current->type == 3) {
                for (const string& str : current->data_string_array) {
                    if (str == searchData) {
                        return index;
                    }
                }
            }
            break;
        case 4:
            if (current->type == 4 && (current->data_struct.field3 == searchData || current->data_struct.field4 == searchData)) {
                return index;
            }
            break;
        default:
            return -1; // Неверный тип поиска
        }
        current = current->next;
    }
    return -1; // Элемент не найден
}

// Функция для освобождения памяти, выделенной под список
void FreeListMemory(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    Node* head = nullptr;

    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить элемент в список" << endl;
        cout << "2. Вывести длину списка" << endl;
        cout << "3. Поиск элемента" << endl;
        cout << "4. Выйти из программы" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            Node* newNode = CreateNode();
            if (newNode != nullptr) {
                AddNodeToEnd(head, newNode);
                cout << "Элемент успешно добавлен в список." << endl;
            }
        }
        else if (choice == 2) {
            int length = GetListLength(head);
            cout << "Длина списка: " << length << endl;
        }
        else if (choice == 3) {
            int searchType;
            string searchData;

            cout << "Выберите тип поиска (1 - строка, 2 - число, 3 - строка в массиве, 4 - строка в структуре): ";
            cin >> searchType;
            cout << "Введите данные для поиска: ";
            cin >> searchData;

            int result = SearchInList(head, searchType, searchData);
            if (result != -1) {
                cout << "Элемент найден в позиции " << result << endl;
            }
            else {
                cout << "Элемент не найден." << endl;
            }
        }
        else if (choice == 4) {
            FreeListMemory(head);
            break;
        }
        else {
            cout << "Неверный выбор. Пожалуйста, выберите корректный пункт меню." << endl;
        }
    }

    return 0;
}
