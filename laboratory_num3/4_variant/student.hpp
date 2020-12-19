# ifndef STUDENT_H
# define STUDENT_H
#include <string> 
#include <vector>
#include <map>


struct Student{
    // персональные данные о студенте 
    std::string name; 
    std::string lastName;
    std::string patronymic; 
    // дисциплины пересдачи относящиеся к студенту:
    //std::vector <AcademicDiscipline> vec_AcademicDiscipline;
    
    // назавние - ключь 
    std::map <std::string, int> academicDiscipline;
};

void 

#endif 