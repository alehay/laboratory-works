/* Есть информация о сотрудниках предприятия: фамилия и инициалы работника, 
 * занимаемая им должность, год поступления на работу. Сформировать список 
 * работников предприятия, чей стаж работы превышает значение, введенное с клавиатуры.
 */
#include <iostream>
#include <istream>
#include <vector>
#include "person.hpp"

int main () {
    std::cout << "укажите количество сотрудников   : " << std::endl;
    int qtyPerson;
    std::cin >> qtyPerson;
    // для хранания используем stl vector 
    std::vector <Person> vec_person ;
    vec_person.reserve(qtyPerson);

    for (int i = 0; i < qtyPerson ; ++i) {
        vec_person.emplace_back(Person(true));
        std::cout << "*********************" << std::endl;
    }

/*
    // цикл ввода 
    for (int i = 0 ; i < qtyPerson ; ++i ) {
        writePreson( vec_person.at(i) );
        if (i < qtyPerson - 1) {    
            std::cout << "***** следующая запись *****" << std::endl;
        } else {
            std::cout << "***** конец ввода *****"<< std::endl;
        }
    }
*/
    //цикл вывода 
    /*
    std::cout << "сотрудники чей возраст превышает " << ageLimit << " : " << std::endl;
    std::cout << std::endl;
    for (int i = 0 ; i < qtyPerson ; ++i ) {   
        if (vec_person.at(i).age > ageLimit) {
            std::cout << vec_person.at(i).name << ", ";
        }
    }
    */
    std::cout << std::endl;

    return 0;
}