#include "matrix.h"



Matrix string_to_matrix(char* text, int rows, int cols){
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;


    mat.data = new char*[rows];
    if (mat.data = nullptr){
        throw std::bad_alloc();
    }

    for (int i = 0; i < mat.rows; i++){
        mat.data[i] = new char[cols];
        for (int j; j < mat.cols; j ++){
            mat.data[i][j] = text[i * mat.cols + j];
        }

    }
    
    return mat;
}