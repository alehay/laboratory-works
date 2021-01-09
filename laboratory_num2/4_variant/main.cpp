/* Поменять местами минимальный и максимальный 
 * элементы главной диагонали мат­рицы 
 * (многомерного вектора v[5][5]).
 */
#include <iostream>
#include <limits>
#include <algorithm>
#include "mymatrix.hpp"


int main(int, char**) {
    myMatrix<double> matrix;
    matrix.load("matrix.txt");
    
    matrix.print();
    std::cout << "********"<<std::endl;
    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::min();

    int i {0};
    int index_max{-1};
    int index_min{-1};
    matrix.row() < matrix.column() ? i = matrix.row() - 1 : i = matrix.column() - 1 ;
    for (;i >= 0; --i) {
        std::cout << matrix[i][i]<<std::endl;
        if (matrix[i][i] > max ) { 
            max =  matrix[i][i] ;
            index_max = i;
        }
        
        if (matrix[i][i] < min ) {
            min =  matrix[i][i];
            index_min = i;     
        }
    }

    if (index_max != index_min) {
        std::swap (matrix[index_min][index_min], matrix[index_max][index_max]);
    }
    std::cout<< "***************" <<std::endl; 
    matrix.print();

}