#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

// структура хранит данные о сотруднике
struct Person{
    std::string name; 
    std::string surname;
    short int  age;
};

void writePreson (Person & person_in); 
template <typename T>
bool write (T & var , std::string ask);

#endif