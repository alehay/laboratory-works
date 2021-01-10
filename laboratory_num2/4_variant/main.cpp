/* Поменять местами минимальный и максимальный 
 * элементы главной диагонали мат­рицы 
 * (многомерного вектора v[5][5]).
 */
#include <iostream>
#include <limits>
#include <algorithm>
#include "mymatrix.hpp"


int main(int, char**) {
    //создаем обьект класса 
    myMatrix<double> matrix;
    // загружаем из файла 
    matrix.load("matrix.txt");
    //печатаем 
    matrix.print();
    
    //храним  кранее значения
    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::min();

    int i {0};
    int index_max{-1};
    int index_min{-1};
    // если матрица окажется не квадратной, ищем кратчайшую сторону. 
    matrix.row() < matrix.column() ? i = matrix.row() - 1 : i = matrix.column() - 1 ;
    for (;i >= 0; --i) {
        // ищем наибольший
        if (matrix[i][i] > max ) { 
            max =  matrix[i][i] ;
            index_max = i;
        }
        // ищем наименьший
        if (matrix[i][i] < min ) {
            min =  matrix[i][i];
            index_min = i;     
        }
    }
    // если индексы не изменились т.е. = -1 или максимальный и минимальный элемент одинаковы 
    // то делать ничего не будетм 
    if (index_max != index_min) {
        std::swap (matrix[index_min][index_min], matrix[index_max][index_max]);
    } else { std::cout << "atantion no swap"<<std::endl; }
    std::cout<< "***************" <<std::endl; 
    matrix.print();

}