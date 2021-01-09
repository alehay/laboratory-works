/* Исходные числовые данные выбираются произвольно.
 * Вычислить сумму положительных и количество 
 * отрицательных элементов многомерного вектора v[5][5].
 */
#include <iostream>
#include "mymatrix.hpp"
#include <vector> 

int main(int, char**) {

myMatrix<double> matrix;
  matrix.load("matrix1.txt");
  matrix.print();

  for(int i = 0; i < matrix.row(); ++i){
    for(int j = 0; j < matrix.column(); ++j){
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
