#include "student.hpp"
#include <iostream>

void wiriteStudent (Student & Student_in) {
    write ( Student_in.name, "имя");
    write ( Student_in.surname, "фамилия");
    write ( Student_in.patronymic, "отчество");
    write ( Student_in.curent_academicDiscipline, "список пересдач");
}

template <typename T>
bool write (T & var , std::string ask) {
    bool imputComplete = false;
    
    if constexpr (std::is_same_v < T, std::map <std::string, int> >) {
        std::cout << ask << std::endl;
        for (auto & [discipline,  retake]: var ) {
            std::cout <<  "дисциплина : " << discipline << std::endl;
            std::cout << "количество преесдач :  " ;
            std::cin >> retake;
        }
    } else {
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
    }    
    return imputComplete;
}