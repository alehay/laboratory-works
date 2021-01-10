/* В целочисленной квадратной матрице (многомерном векторе v[5][5]) 
 * определить но­мера строк (значение векторов указателей на векторы), 
 * все элементы которых чётные, найти суммы элементов этих строк.
 */
#include <iostream>
#include <map>
#include "mymatrix.hpp"

int main(int, char**) {
    // создаем экземпляр шаблона класса типа int 
    myMatrix<int> matrix;
    // загружаем матрицу из файла
    matrix.load("matrix.txt");
    // храним номера строк чьи элементы четные
    // и суммы элементов этих строк
    std::map<int,long> odded_row; 
    // печатаем матрциу
    matrix.print(); 
    std::cout << "**********" << std::endl; 

    // итерируемся по матрице
    for (int i = 0; i < matrix.row(); ++i ) {
        // аккумулятор
        int accum {0};
        for (int j = 0 ; j < matrix.column() ; ++j) {
            // певый в строке не четный в строке элемент...
            if (matrix[i][j]&1) {
                // ...обнулит аккумулятор..
                accum = 0;
                // .. и сбросит цикл 
                break;
            } else {
                // если не четных не нашли храним аккумулятор
                accum += matrix[i][j];
                // пройдя всю строку сохраняем аккумулятор и номер страки в Map
                if (j == matrix.column() - 1) { odded_row.insert ({i, accum}); }
            }
        }
    }
    // печатаем результат 
    for (auto & [row, sum] : odded_row ) {
        std::cout << "строка : " << row + 1<< " cумма : " <<  sum  << std::endl; 
    } 
}