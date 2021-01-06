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

// шаблонная фуннкция выбираем вариант копиляции
// вызывается в конструкторе структуры
template <typename T>
bool write (T & var , const std::string  ask) {
    bool inputComplete = false;
    // если заполняем передсдачи 
    if constexpr (std::is_same_v < T, std::map <std::string, int> >) {
        std::cout << ask << std::endl;
        for (auto discip : academicDiscipline) {
            std::cout << "предмет : " <<  discip << "\t" ;
            std::cout << "количество пересдач : ";
            int count {0}; 
            std::cin >> count;
            // если не нуль, сохраняем предсдачу лишнее не хнарим!
            if (count) {
                var.insert ({discip , count});
            }
        }
    } else {
        // если заполняем  ФИО
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

// данные о студенте в структуре
struct Student{
    std::string name; 
    std::string surname;
    std::string patronymic; 
    // храним данные о передсдачах
    std::map <std::string, int> curent_academicDiscipline;

    // если init - true инициализируем переменные в специальном констукторе.
    Student (bool init){
        if (init) {
            write ( name, "имя");
            write ( surname, "фамилия" );
            write ( patronymic, "отчество") ;
            write ( curent_academicDiscipline, "Пересдача "); 
        } 
    }
    //  перегрузка вывода, для удобства
    friend std::ostream & operator<< (std::ostream &out, const Student & student) {
        return out << student.surname << " " << student.name; 
    }
    // печать задолжностей
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
    
    // итеримся по вектору студентов
    for (auto student_it = students.begin() ; 
    student_it != students.end(); ++student_it) {
        //  если find обнаружил задолжность, мы ее сохраняем 
        if( auto it ( student_it->curent_academicDiscipline.find(disp));    
        it !=  student_it->curent_academicDiscipline.end()) {
            debStudents.insert (student_it);
        }
    }

    //выводим найденых студентов в списке должников
    for (auto & student : debStudents ) {
        std::cout << *student << " : ";
        student->debtPrint(disp);
    }

}
//  процедура сепаратор
void sep (std::string message = " разделитель ") {
    std::cout<<std::endl;
    for (int i = 0; i < 40; ++i) {std::cout << "*";}
    std::cout<<std::endl;
    int pos = (40 - message.size())/2;
    for (int i = 0; i < pos  ; ++i) {std::cout << "*";}
    std::cout<< "\t" << message << "\t";
    for (int i = 0; i < pos  ; ++i) {std::cout << "*";}
     std::cout<<std::endl;
    for (int i = 0; i < 40; ++i) {std::cout << "*";}
    std::cout<<std::endl;
}

#endif 

