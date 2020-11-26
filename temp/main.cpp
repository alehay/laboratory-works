#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    std::string pathFromFile = "text.txt" ; // проверяем файл
    std::ifstream fileIn;
    fileIn.open(pathFromFile);
    if (!fileIn.is_open()) { // если что то пошло не так, мы не нашли файл
        std::cout << "text.txt не найден, проверте файл ! " << std::endl;
        return 0;
    }

    std::vector <std::string> textVec;
    std::string temp;
    while (!fileIn.eof() ) { // читаем до конца
        std::getline (fileIn,temp);
        textVec.push_back(temp);
    }

    while (true) {  // главный цикл програмы
        std::cout << "введите слово и фразу для поиска : " << std::endl;
        std::string stringFind;
        std::getline (std::cin,stringFind);
        unsigned int stringPos {0};
        // auto не испльзовал для наглядности, но компилятор знает !
        for (std::vector<std::string >::iterator it = textVec.begin() ; it != textVec.end(); ++it) {
            std::size_t found = it->find(stringFind);
            if(found != std::string::npos) {

                std::cout << "искомая фраза обнаружена в строке : " << stringPos  << std::endl;
                std::cout << "на позиции : " << found  << " символ " << std::endl;

                std::cout << it-> substr(found ,stringFind.size() );
                std::cout << std::endl;
                break;
            }
            ++stringPos;
       }
    }

    return 0;
}
