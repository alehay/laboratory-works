#include "person.hpp"


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