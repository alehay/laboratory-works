#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

const int ageLimit = 33; 

struct Person{
    std::string name; 
    std::string surname;
    short int  age;
};

bool writePreson (Person & person_in); 
template <typename T>
bool write (T & var , std::string ask);

#endif