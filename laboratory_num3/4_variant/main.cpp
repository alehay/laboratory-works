/* Сформировать список о зарегистрированных пересдачах 
 * задолженностей студентов: ФИО, предмет, количество пересдач.
 * Распечатать список  по количеству  пересдач и выдать его на экран дисплея.
 */
#include <iostream>
#include <istream>
#include <vector>

const int ageLimit = 33;

int main () {
    std::cout << "укажите количество сотрудников для ввода или 0 для выхода : " << std::endl;
    int qtyPerson;
    std::cin >> qtyPerson;
    std::vector <Person> vec_person (qtyPerson);

    for (int i = 0 ; i < qtyPerson ; ++i ) {
        writePreson( vec_person.at(i) );
        if (i < qtyPerson - 1) {    
            std::cout << "***** следующая запись *****" << std::endl;
        } else {
            std::cout << "***** конец ввода *****"<< std::endl;
        }
    }

    std::cout << "сотрудники чей возраст превышает " << ageLimit << " : " << std::endl;
    std::cout << std::endl;
    for (int i = 0 ; i < qtyPerson ; ++i ) {   
        if (vec_person.at(i).age > ageLimit) {
            
            std::cout << vec_person.at(i).name << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}