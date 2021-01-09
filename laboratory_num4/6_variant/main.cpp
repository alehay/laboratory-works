#include <iostream>
#include <cmath>

double func (double x) {
    return x*x*x+(3*x*x)+std::atan(x);  
}


int  main( int argc, char *  argv[] )  {

    double b  {3.8} , c {3.2};
    for (int a = -5; a <= 4 ; ++a) {
       std::cout << (func (a) - func (b))/ func (c) << std::endl; 
    }

    

    return 0;
}