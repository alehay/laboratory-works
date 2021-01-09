#ifndef MY_MATRIX_H
#define MY_MATRIX_H
#include <iostream> 


template <class T>
class myMatrix{
private:
    int rows_count {0};
    int columns_count {0};
    //int size; 
    bool is_exist {false};
    T* rowsPtr {nullptr}; 
    
    
    bool allocator ();

public:
    explicit myMatrix ();
    explicit myMatrix (int in_rows , int in_columns );
    
    //double sumPositive ();
    void print();
    bool load(const std::string & path);
    bool input();
    ~myMatrix (); 
};
#endif // !MATRIX_H
