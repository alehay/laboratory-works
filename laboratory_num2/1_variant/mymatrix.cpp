#include "mymatrix.hpp"

template<class T>  
myMatrix<T>::MyMatrix (int in_rows , int in_columns ) 
    : rows (in_rows), columns(in_columns)  {
    rowsPtr = new T * [rows];
    for (int i = 0; i < rows ; ++i) {
        rowsPtr [i] = new T [columns];
    }
}
