# ifndef STUDENT_H
# define STUDENT_H

#include <string> 
#include <vector>
#include <map>
#include <type_traits> 
#include <iostream>
#include <set>

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
        
    friend std::ostream & operator<< (std::ostream &out, const Student & student) {
        return out << student.surname << " " << student.name; 
        
    } 

    void debtPrint (const std::string & discip ) const {
         
        if( auto it (curent_academicDiscipline.find(discip));    
            it !=  curent_academicDiscipline.end()) {
                std::cout << it->second  << std::endl;
        } 
    }
    

};



void findAndPrint (const std::string & disp,
                   const std::vector <Student> & students
                   ) {
    
    std::set < std::vector<Student>::const_iterator > debStudents;
    
    // TODO перенести после сета, и проверить на то пустой он или нет ....
    std::cout << "Должники по предмету " << disp << " : " << std::endl; 

    for (auto student_it = students.begin() ; 
    student_it != students.end(); ++student_it) {
        
        if( auto it ( student_it->curent_academicDiscipline.find(disp));    
        it !=  student_it->curent_academicDiscipline.end()) {
            debStudents.insert (student_it);
        }

    }
    for (auto & student : debStudents ) {
        std::cout << *student;
        student->debtPrint(disp);
    }

}



#endif 

