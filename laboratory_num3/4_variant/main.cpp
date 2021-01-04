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
        for (int i = 0 ; i < argc; i++) {
           std::cout << argv[i];  
        } 
    }
    std::string alehay {"aaaa"};
    Student student {alehay, alehay, alehay};
    
    std::cout << "Hellow  world" << std::endl;

    return 0;
}