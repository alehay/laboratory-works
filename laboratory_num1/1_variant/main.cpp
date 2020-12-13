/* лаборатораня работа, 
 * Ввести в ЭВМ информацию о сотрднике отдела : фамилия , имя возраст. 
 * Распечатать имена сотрудников, возраст которых превышает 33 года. 
 */
#include <iostream>
#include <istream>
#include <vector>
#include "person.hpp"

const int ageLimit = 33;

int main () {
    std::cout << "укажите колиество сотрудников для ввода или 0 для выхода : " << std::endl;
    int qtyPerson;
    std::cin >> qtyPerson;
    std::vector <Person> vec_person (qtyPerson);

    for (int i = 0 ; i < qtyPerson ; ++i ) {
        writePreson( vec_person.at(i) );
    }

     for (int i = 0 ; i < qtyPerson ; ++i ) {
        
        if (vec_person.at(i).age > ageLimit) {
            std::cout << vec_person.at(i).name;
        }
    }

    return 0;
}