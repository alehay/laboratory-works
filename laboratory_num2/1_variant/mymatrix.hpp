#ifndef MY_MATRIX_H
#define MY_MATRIX_H

template <class T>
class myMatrix{
private:
    int rows;
    int columns;
    int size; 
    T* ptr; 

public:
    explicit MyMatrix (int in_rows = 1, int in_columns = 1);

    sumPositive ();
};
#endif // !MATRIX_H
