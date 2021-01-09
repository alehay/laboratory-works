#include <iostream>

double func (double z) {
    return 2 * 3.14159265 * z;
}

int  main( int argc, char *  argv[] )  {
    

    for (double x = 1.5, y = 3 ; x < 3.7  && y < 8; x += 0.25 , y += 1.25 ){
       double res_x = func (x);
       double res_y = func (y);
       
       std::cout <<  (res_x*res_x + res_y*res_y)/2 << std::endl;  
    }

    return 0;
}