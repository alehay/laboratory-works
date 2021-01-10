#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <vector>


// структура хранит данные о сотруднике
struct Person{
    std::string name; 
    std::string lastname;
    std::string post;
    short int  year;

    Person (bool init);
};

void writePreson (Person & person_in); 
template <typename T>
bool write (T & var , std::string ask);

Person::Person (bool init) {
    if (init) {
        write ( name, "Фамилия");
        write ( lastname, "Инициалы" );
        write ( post, "должность");
        write ( year, "год поступления на работу");
    }
}

// шаблонная фнукция заполнения 
// записываемый тип, тип хранимый структурой.
template <typename T>
bool write (T & var , std::string ask) {
    bool imputComplete = false;
    while (!imputComplete) {
        std::cout <<" пожалуйста введите поле " << ask << " : " ;
        std::cin >> var;
        // контроль валидности данных 
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "ошибка повторите ввод: ";
            continue;
        }
        imputComplete = true;
        break;
    }
    return imputComplete;
}


#endif