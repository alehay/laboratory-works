/* В целочисленной квадратной матрице (многомерном векторе v[5][5]) 
 * определить но­мера строк (значение векторов указателей на векторы), 
 * все элементы которых чётные, найти суммы элементов этих строк.
 */
#include <iostream>
#include <map>
#include "mymatrix.hpp"


int main(int, char**) {
    myMatrix<int> matrix;
    matrix.load("matrix.txt");
    std::map<int,long> odded_row; 

    matrix.print();

    for (int i = 0; i < matrix.row(); ++i ) {
         int accum {0};
        for (int j = 0 ; j < matrix.column() ; ++j) {
            if (matrix[i][j]&1) {
                accum = 0;
                break;
            } else {
                accum += matrix[i][j];
                if (j == matrix.column() - 1) { odded_row.insert ({i, accum}); }
            }
        }
    }

    for (auto & [row, sum] : odded_row ) {
        std::cout << "строка : " << row << " cумма : " <<  sum  << std::endl; 
    } 
}