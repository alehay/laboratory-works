#ifndef MY_MATRIX_H
#define MY_MATRIX_H
#include <iostream> 
#include <fstream>


template <class T>
class myMatrix{
private:
    // информация о матрице
    int rows_count {0};
    int columns_count {0};
    //int size; 
    bool is_exist {false};
    // указатель на матрицу
    T** rowsPtr  {nullptr}; 
    // выделение памяти     
    bool allocator ();

public:
    explicit myMatrix ();
    explicit myMatrix (int in_rows , int in_columns );
    
    //double sumPositive ();
    void print();
    bool load(const std::string & path);
    bool input();
    ~myMatrix ();

    T sum_pos ();
    int negative_count ();  


  // перегрузка опереторов квадратные скобки
    T* operator[] (int i){
    return rowsPtr[i];
  }

  int row(){
    return rows_count;
  }

  int column(){
    return columns_count;
  }
};


template<class T>  
myMatrix<T>::myMatrix () {}

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
            std::cout << rowsPtr [i][j] << " ";
        }
        std::cout << std::endl;
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
        } else { 
            std::cout << "файл не найден" << std::endl; 
        }
        T temp; 
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

template<class T> 
T myMatrix<T>::sum_pos () {
    T temp {0};
    for (int i = 0; i < rows_count; ++i ) {
        for (int j = 0; j < columns_count; ++j ) {
            if (rowsPtr [i][j] > 0) {
                temp += rowsPtr [i][j] ;
            }
        }
    } 
    return temp;  
}

template<class T> 
int  myMatrix<T>::negative_count () {
    int count{0}; 
    for (int i = 0; i < rows_count; ++i ) {
        for (int j = 0; j < columns_count; ++j ) {
            if (rowsPtr [i][j] < 0) {
                ++count ;
            }
        }
    }
    return count;
}

#endif // !MATRIX_H
