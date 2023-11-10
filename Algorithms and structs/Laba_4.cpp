#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Структура для хранения данных респондента
struct Respondent {
    int age;
    string gender;
    string education;
    string answer;
    Respondent* next;
    Respondent* prev;
};

// Функция для создания нового респондента
Respondent* createRespondent(int age, const string& gender, const string& education, const string& answer) {
    Respondent* newRespondent = new Respondent;
    newRespondent->age = age;
    newRespondent->gender = gender;
    newRespondent->education = education;
    newRespondent->answer = answer;
    newRespondent->next = nullptr;
    newRespondent->prev = nullptr;
    return newRespondent;
}

// Функция для добавления респондента в список
void addRespondentToList(Respondent*& head, Respondent* newRespondent) {
    if (head == nullptr) {
        head = newRespondent;
    }
    else {
        Respondent* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newRespondent;
        newRespondent->prev = temp;
    }
}

// Функция для подсчета статистики
void countStatistics(Respondent* head) {
    int a_count = 0, b_count = 0, c_count = 0;

    Respondent* current = head;
    while (current != nullptr) {
        // а) сколько мужчин старше 40 лет, имеющих высшее образование, ответили ДА
        if (current->gender == "мужчина" && current->age > 40 && current->education == "высшее" && current->answer == "ДА") {
            a_count++;
        }
        // б) сколько женщин моложе 30 лет, имеющих среднее образование, ответили НЕТ
        if (current->gender == "женщина" && current->age < 30 && current->education == "среднее" && current->answer == "НЕТ") {
            b_count++;
        }
        // в) сколько мужчин моложе 25 лет, имеющих начальное образование, ответили ДА
        if (current->gender == "мужчина" && current->age < 25 && current->education == "начальное" && current->answer == "ДА") {
            c_count++;
        }
        current = current->next;
    }

    // Вывод результатов статистики
    cout << "а) " << a_count << " мужчин старше 40 лет, имеющих высшее образование, ответили ДА." << endl;
    cout << "б) " << b_count << " женщин моложе 30 лет, имеющих среднее образование, ответили НЕТ." << endl;
    cout << "в) " << c_count << " мужчин моложе 25 лет, имеющих начальное образование, ответили ДА." << endl;
}

// Функция для вывода всех анкет и ответов на вопросы
void displayAllRespondents(Respondent* head) {
    cout << "Список всех анкет и ответов на вопросы:" << endl;

    Respondent* current = head;
    while (current != nullptr) {
        cout << "Возраст: " << current->age << ", Пол: " << current->gender << ", Образование: " << current->education << ", Ответ: " << current->answer << endl;
        current = current->next;
    }
}

void addRespodent(int age, string gender, string education, string answer, Respondent* head) {
    cout << "Введите возраст: "; cin >> age;
chooseGender:
    cout << "Выберите пол:" << endl << "1. Мужчина" << endl << "2. Женщина" << endl << "Ввод: ";
    cin >> gender;
    if (gender == "1") {
        gender = "мужчина";;
    }
    else if (gender == "2") {
        gender = "женщина";
    }
    else {
        cout << "Ошибка! Введите 1 или 2" << endl << endl;
        goto chooseGender;
    }
    cout << "Ваш пол: " << gender << endl << endl;

chooseEducation:
    cout << "Выберите образование:" << endl << "1. Высшее" << endl << "2. Среднее" << endl << "3. Начальное" << endl << "Ввод: ";
    cin >> education;
    if (education == "1") {
        education = "высшее";;
    }
    else if (education == "2") {
        education = "среднее";
    }
    else if (education == "3") {
        education = "начальное";
    }
    else {
        cout << "Ошибка! Введите 1, 2 или 3" << endl;
        goto chooseEducation;
    }
    
chooseAnswer:
    cout << "Выберите ответ:" << endl << "1. Да" << endl << "2. Нет" << endl << "Ввод: ";
    cin >> answer;
    if (answer == "1") {
        answer = "ДА";;
    }
    else if (answer == "2") {
        answer = "НЕТ";
    }
    else {
        cout << "Ошибка! Введите 1 или 2" << endl;
        goto chooseAnswer;
    }

    cout << "Ваш ответ: " << answer << endl << endl;

    addRespondentToList(head, createRespondent(age, gender, education, answer));
}

int main() {
    setlocale(LC_ALL, "RU");

    Respondent* head = nullptr;
    int age = 0;
    string gender;
    string education;
    string answer;

    // Пример начального ввода анкет
    addRespondentToList(head, createRespondent(25, "мужчина", "высшее", "ДА"));

    int menu;

    while (true)
    {
        cout << "Яхьяев Данис ДИНРБ-21/2. Вариант №18(8)\n\n";

        cout << "1. Добавить респодента" << endl;
        cout << "2. Посмотреть статистику" << endl;
        cout << "3. Посмотреть всех респодентов" << endl;
        cout << "0. Выход" << endl;
        cout << "Ввод: ";
        
        cin >> menu;

        if (menu == 1) {
            system("cls");
            addRespodent(age, gender, education, answer, head);
            system("pause");
            system("cls");
        }
        else if (menu == 2) {
            system("cls");
            countStatistics(head);
            system("pause");
            system("cls");
        }
        else if (menu == 3) {
            system("cls");
            displayAllRespondents(head);
            system("pause");
            system("cls");
        }
        else if (menu == 0) {
            goto end;
        }
        else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
            system("cls");
        }
    }

    // Освобождение памяти
    while (head != nullptr) {
        Respondent* temp = head;
        head = head->next;
        delete temp;
    }
end:
    return 0;
}
