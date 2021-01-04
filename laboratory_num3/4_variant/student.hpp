# ifndef STUDENT_H
# define STUDENT_H

#include <string> 
#include <vector>
#include <map>
#include <type_traits> 
#include <iostream>

constexpr int countDiscipline {6};
// храним предметы 
std::array <std::string, countDiscipline > academicDiscipline  
{ "Сопромат", "теорМех",
  "ТФКП", "ТеорВер", 
  "ТММ", "физика" };

template <typename T>
bool write (T & var , const std::string  ask) {
    bool inputComplete = false;
    if constexpr (std::is_same_v < T, std::map <std::string, int> >) {
        std::cout << ask << std::endl;
        for (auto discip : academicDiscipline) {
            std::cout << "предмет : " <<  discip << "\t" ;
            std::cout << "количество пересдач : ";
            int count {0}; 
            std::cin >> count;
            if (count) {
                var.insert ({discip , count});
            }
        }
      
    } else {
        while (!inputComplete) {
            std::cout <<" пожалуйста, введите поле " << ask << " : " ;
            std::cin >> var;
            // контроль валидности данных 
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "ошибка повторите ввод: ";
                continue;
            }
            inputComplete = true;
            break;
        }
    }    
    return inputComplete;
}

// данные о студенте 
struct Student{
    std::string name; 
    std::string surname;
    std::string patronymic; 
    std::map <std::string, int> curent_academicDiscipline;

    // если init - true инициализируем переменные.  
    Student (bool init){
        if (init) {
            write ( name, "имя");
            write ( surname, "фамилия" );
            write ( patronymic, "отчество") ;
            write ( curent_academicDiscipline, "Пересдача "); 
        } 
    }    
};




#endif 

