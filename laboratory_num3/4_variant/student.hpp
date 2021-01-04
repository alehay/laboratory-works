# ifndef STUDENT_H
# define STUDENT_H
#include <string> 
#include <vector>
#include <map>
/* создадим пару предмет количество пересдачь, 
*  которая будет хранится в map 
*/

std::map <std::string, int> academicDiscipline = 
{{ "сопромат", 0 },
 { "теорМех",  0 }, 
 { "ТФКП",     0 }, 
 { "ТеорВер",  0 },
 { "ТММ "   ,  0 }
 };


struct Student{
    // персональные данные о студенте 
    std::string name; 
    std::string surname;
    std::string patronymic; 
    std::map <std::string, int> curent_academicDiscipline;
    // дисциплины пересдачи относящиеся к студенту:
    
    //в конструкторе берем имя фамилию и список дициплин
    Student(std::string n , std::string  s , std::string p ) :
    name {n}, surname  {s}, patronymic {p} {
        curent_academicDiscipline = academicDiscipline;
    }
};

void wiriteStudent (Student & Student_in);
template <typename T>
bool write (T & var , std::string ask);



#endif 