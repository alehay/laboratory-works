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
  std::cout << "************" << std::endl;
  std::cout << "сумма позитивных элементов : " << std::endl;
  std::cout << matrix.sum_pos() << std::endl;
  std::cout << "количество негативных элементов : " << std::endl;
  std::cout << matrix.negative_count() << std::endl;



}
