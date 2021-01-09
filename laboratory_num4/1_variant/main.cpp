#include <iostream>

double func (double * x , double * y , double * c , double * z, 
             int size_x,  int size_y, int size_c, int size_z )  {
            
  double sum_x {0};
            for (int i_x = 0; i_x < size_x ; ++i_x) {
              sum_x += x[i_x];
            }

  double prod_y {1};
            for (int i_y = 0; i_y < size_y ; ++i_y) {
              prod_y *= y[i_y];
            }
  
  double sum_c {0};
            for (int i_c = 0; i_c < size_c ; ++i_c) {
              sum_c *= c[i_c];
            }

  double prod_z {1};
            for (int i_z = 0; i_z < size_z ; ++i_z) {
              prod_z *= c[i_z];
            }

  return (sum_x + prod_y) / (sum_c + prod_z);
}

int main(int, char**) {

double x_arr[] = {1,2,3,4,5,6,7,8};
double y_arr[] = {1,2,3,4,5,6,7,8};
double c_arr[] = {1,2,3,4,5,6,7,8};
double z_arr[] = {1,2,3,4,5,6,7,8};

std::cout << std::endl;
std::cout << func (x_arr, y_arr, c_arr, z_arr , 8, 8 , 8 , 8);
std::cout << std::endl;


}
