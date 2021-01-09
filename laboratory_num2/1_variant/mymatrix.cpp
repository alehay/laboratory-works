#include "mymatrix.hpp"
#include <fstream>


template<class T>  
myMatrix<T>::myMatrix () {

}

template<class T>  
myMatrix<T>::myMatrix (int in_rows , int in_columns ) 
    : rows_count (in_rows), columns_count(in_columns)  {
    
    if ( rows_count < 1 || columns_count < 1 ) {
        is_exist = false; 
    } else {
       is_exist = allocator ();
    }
}

template<class T>  
bool myMatrix<T>::allocator () {

    rowsPtr = new T * [rows_count]; // vertical y
    for (int i = 0; i < rows_count ; ++i) {
        rowsPtr [i] = new T [columns_count]; // horizontal x
    } 
    return true; 
}

template<class T>  
myMatrix<T>::~myMatrix  () {
    for (int i = 0; i < rows_count ; ++i ) { 
        delete [] rowsPtr [i];
    }
    delete [] rowsPtr;
}

template<class T> 
void myMatrix<T>::print() {
    for (int i = 0 ; i < rows_count ; ++i ) {
        for (int j = 0 ; j < columns_count ; ++ j  ) {
            std::cout << rowsPtr [i][j];
        }
    }
}

template<class T> 
bool myMatrix<T>::load(const std::string & path) { 
    if (!is_exist) {
        std::ifstream ifs;
        ifs.open (path);
        if(ifs.is_open() ) {
            ifs >> rows_count >> columns_count ;
            allocator ();
        }
        for (int i = 0; i < rows_count; ++i ) {
            for (int j = 0; j < columns_count; ++j ) {
                ifs >> rowsPtr [i][j] ;
            }
        } 
        return true; 
    } else {
        return false; 
    }
}
