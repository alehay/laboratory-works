/* Сформировать список о зарегистрированных пересдачах 
 * задолженностей студентов: ФИО, предмет, количество пересдач. 
 * Распечатать список по количеству пересдач и выдать его на экран дисплея.
 */
#include <iostream>
#include <istream>
#include <vector>
#include <fstream>


int main () {
    std::string pathFromFile = "text.txt" ; // проверяем файл
    std::ifstream fileIn;
    fileIn.open(pathFromFile);
    if (!fileIn.is_open()) { // если что то пошло не так, мы не нашли файл
        std::cout << "text.txt не найден, проверте файл ! " << std::endl;
        return 0;


    return 0;
}