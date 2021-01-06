/* Есть информация о сотрудниках предприятия: фамилия и инициалы работника, 
 * занимаемая им должность, год поступления на работу. Сформировать список 
 * работников предприятия, чей стаж работы превышает значение, введенное с клавиатуры.
 */
#include <iostream>
#include <istream>
#include <vector>
#include <ctime>
#include "person.hpp"

int main () {

    time_t now = time(0); // получаем время эпохи UTC
    tm *ltm = localtime(&now); // структура которая представляет время

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

    std::cout << "введите требуемый стаж на текущий момент : ";
    int seniority;
    std::cin >>  seniority;
    
    std::cout <<  "сотрудники чей стаж превыешает : " << seniority << std::endl;

 
        for (auto & [name, lastname , post, year] :  vec_person)  {
            if (seniority < ( ltm->tm_year - year + 1900)) {
                std::cout <<name << "" << lastname << " " << post << std::endl;
            }           
        }
     std::cout << std::endl;

    return 0;
}