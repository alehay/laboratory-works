#include "student.hpp"

void writeStudent (Student & student_in) {

}

template <typename T>
bool write (T & var , std::string ask) {
    bool imputComplete = false;
    while (!imputComplete) {
        std::cout <<" пожалусто введите " << ask << " : " ;
        std::cin >> var;
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