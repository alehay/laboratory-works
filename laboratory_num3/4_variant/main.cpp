/* Сформировать список о зарегистрированных пересдачах 
 * задолженностей студентов: ФИО, предмет, количество пересдач.
 * Распечатать список  по количеству  пересдач и выдать его на экран дисплея.
 */
#include <iostream>
#include <istream>
#include <vector>
#include "student.hpp"

int  main( int argc, char *  argv[] )  {
    if(argc) {
        for (int i = 0 ; i < argc; ++i) {
           std::cout << argv[i];  
        } 
    }

// спросить сколько студентов, 
std::cout << "пожалуйста введите количество студентов : " ;
int countStudents {0};
std::cin >> countStudents ;
// создаем верктор что бы хранить студентов ;
std::vector < Student >  students; 
//  выделяем место под обьекты
students.reserve(countStudents);

// инициализация студентов 
for (int i = 0; i < countStudents; ++i) {
    students.emplace_back(Student (true));
    sep("следующий студент");
}

for (auto & student : students ) {
    sep("долги студента");
    std::cout << student.name << " " <<
    student.surname << " " << student.patronymic <<  std::endl; 
    for (auto & [disp, count] : student.curent_academicDiscipline) {
        std::cout << "дисциплина " << disp << std::endl;
        std::cout << "количество пересдач : " << count << std::endl; 
    }
    
}

for (auto & dicip : academicDiscipline ) { 
    sep ("долги студентов по диcциплинам");
    findAndPrint (dicip , students );
}
    return 0;
}