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
std::vector < Student >  students; 
students.reserve(countStudents);



for (int i = 0; i < countStudents; ++i) {
    students.emplace_back(Student (true));
}

for (auto & student : students ) {

    std::cout << student.name << " " <<
    student.surname << " " << student.patronymic <<  std::endl; 
    
    for (auto & [disp, count] : student.curent_academicDiscipline) {
        std::cout << "дисциплина " << disp << std::endl;
        std::cout << "количество пересдач " << count << std::endl; 

    }
    std::cout<< "*****" << std::endl;

}


/* тест функционала печати академических задолждностей 
for (auto & dicip : academicDiscipline ) {
   for (auto & student : students )  {
       std::cout << student << std::endl; 
       student.debtPrint(dicip);
   }

}
*/


for (auto & dicip : academicDiscipline ) { 
    findAndPrint (dicip , students );
}

// ввести студентов и академические задолженности... 
// вывод по количеству пересдач ...
    return 0;
}