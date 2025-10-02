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

Matrix encrypt(Matrix chars) {
    Matrix result;
    result.rows = chars.rows;
    result.cols = chars.cols;

    result.data = new char*[result.rows];

    for (int i = 0; i < chars.rows; i++) {
        result.data[i] = new char[result.cols];
    }

    for (int i = 0; i < chars.rows; i++) {
        for (int j = 0; j < chars.cols; j++) {
            result.data[i][j] = chars.data[j][i];
        }
    }

    return result;
}

std::string decrypt(Matrix encrypted) {
    
    std::string result = "";

    for (int j = 0; j < encrypted.cols; j++) {
        for (int i = 0; i < encrypted.rows; i++) {
            result += encrypted.data[j][i];
        }
    }

    return result;
}