/* лаборатораня работа, 
 * Ввести в ЭВМ информацию о сотрднике отдела : фамилия , имя возраст. 
 * Распечатать имена сотрудников, возраст которых превышает 33 года. 
 */
#include <iostream>
#include <istream>
#include <vector>
#include "person.hpp"


int main () {
    std::cout << "укажите колиество сотрудников для ввода или 0 для выхода : " << std::endl;
    int qtyPerson;
    std::cin >> qtyPerson;
    std::vector <Person> person (qtyPerson);

    for (int i = 0 ; i < qtyPerson ; ++i ) {
        writePreson( person.at(i) );
    }

    return 0;
}