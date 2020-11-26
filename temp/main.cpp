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

        // auto не  испльзем для наглядности
       for (std::vector<std::string >::iterator it = textVec.begin() ; it != textVec.end(); ++it) {
            std::size_t found = it->find(stringFind);
            if(found != std::string::npos) {
                std::cout << "искомая фраза обнаружена на позиции : " << found << std::endl;
                break;
            }
        }
    }

    return 0;
}
