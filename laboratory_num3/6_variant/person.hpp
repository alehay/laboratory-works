#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <vector>

// структура хранит данные о сотруднике
struct Person{
    std::string name; 
    std::string post;
    short int  year;

    Person (bool init);
};

void writePreson (Person & person_in); 
template <typename T>
bool write (T & var , std::string ask);

#endif